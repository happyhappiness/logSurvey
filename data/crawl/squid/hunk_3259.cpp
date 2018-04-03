 const char * obtain_challenge(void);
 void manage_request(void);
 
+/* these are part of rfcnb-priv.h and smblib-priv.h */
+extern int SMB_Get_Error_Msg(int msg, char *msgbuf, int len);
+extern int SMB_Get_Last_Error();
+extern int RFCNB_Get_Last_Errno();
+extern int RFCNB_Get_Last_Error(void);
+extern int SMB_Get_Last_SMB_Err(void);
+
 
+/* a few forward-declarations. Hackish, but I don't care right now */
+SMB_Handle_Type SMB_Connect_Server(SMB_Handle_Type Con_Handle, char *server, char *NTdomain);
+
+/* this one is reallllly haackiish. We really should be using anything from smblib-priv.h
+ */
+static char const *SMB_Prots[] = {"PC NETWORK PROGRAM 1.0",
+                                  "MICROSOFT NETWORKS 1.03",
+                                  "MICROSOFT NETWORKS 3.0",
+                                  "DOS LANMAN1.0",
+                                  "LANMAN1.0",
+                                  "DOS LM1.2X002",
+                                  "LM1.2X002",
+                                  "DOS LANMAN2.1",
+                                  "LANMAN2.1",
+                                  "Samba",
+                                  "NT LM 0.12",
+                                  "NT LANMAN 1.0",
+                                  NULL
+                                 };
+
+#define ENCODED_PASS_LEN 24
+#define MAX_USERNAME_LEN 255
+#define MAX_DOMAIN_LEN 255
+#define MAX_PASSWD_LEN 31
+
+static unsigned char challenge[NTLM_NONCE_LEN];
+static unsigned char lmencoded_empty_pass[ENCODED_PASS_LEN],
+ntencoded_empty_pass[ENCODED_PASS_LEN];
+SMB_Handle_Type handle = NULL;
+int ntlm_errno;
+static char credentials[MAX_USERNAME_LEN+MAX_DOMAIN_LEN+2];	/* we can afford to waste */
+static char my_domain[100], my_domain_controller[100];
+static char errstr[1001];
 #if DEBUG
-char error_messages_buffer[BUFFER_SIZE];
+char error_messages_buffer[NTLM_BLOB_BUFFER_SIZE];
 #endif
-
 char load_balance = 0, protocol_pedantic = 0;
 #if NTLM_FAIL_OPEN
 char last_ditch_enabled = 0;
 #endif
-
 dc *controllers = NULL;
 int numcontrollers = 0;
 dc *current_dc;
-
 char smb_error_buffer[1000];
 
-/* signal handler to be invoked when the authentication operation
- * times out */
-static char got_timeout = 0;
-static void
-timeout_during_auth(int signum)
+
+/* Disconnects from the DC. A reconnection will be done upon the next request
+ */
+void
+dc_disconnect()
 {
-    dc_disconnect();
+    if (handle != NULL)
+        SMB_Discon(handle, 0);
+    handle = NULL;
 }
 
-/* makes a null-terminated string upper-case. Changes CONTENTS! */
-static void
-uc(char *string)
+int
+connectedp()
+{
+    return (handle != NULL);
+}
+
+/* Tries to connect to a DC. Returns 0 on failure, 1 on OK */
+int
+is_dc_ok(char *domain, char *domain_controller)
 {
-    char *p = string, c;
-    while ((c = *p)) {
-        *p = xtoupper(c);
-        p++;
+    SMB_Handle_Type h = SMB_Connect_Server(NULL, domain_controller, domain);
+    if (h == NULL)
+        return 0;
+    SMB_Discon(h, 0);
+    return 1;
+}
+
+/* returns 0 on success, > 0 on failure */
+static int
+init_challenge(char *domain, char *domain_controller)
+{
+    int smberr;
+
+    if (handle != NULL) {
+        return 0;
     }
+    debug("Connecting to server %s domain %s\n", domain_controller, domain);
+    handle = SMB_Connect_Server(NULL, domain_controller, domain);
+    smberr = SMB_Get_Last_Error();
+    SMB_Get_Error_Msg(smberr, errstr, 1000);
+
+
+    if (handle == NULL) {	/* couldn't connect */
+        debug("Couldn't connect to SMB Server. Error:%s\n", errstr);
+        return 1;
+    }
+    if (SMB_Negotiate(handle, SMB_Prots) < 0) {		/* An error */
+        debug("Error negotiating protocol with SMB Server\n");
+        SMB_Discon(handle, 0);
+        handle = NULL;
+        return 2;
+    }
+    if (handle->Security == 0) {	/* share-level security, unuseable */
+        debug("SMB Server uses share-level security .. we need user security.\n");
+        SMB_Discon(handle, 0);
+        handle = NULL;
+        return 3;
+    }
+    memcpy(challenge, handle->Encrypt_Key, NTLM_NONCE_LEN);
+    SMBencrypt((unsigned char *)"",challenge,lmencoded_empty_pass);
+    SMBNTencrypt((unsigned char *)"",challenge,ntencoded_empty_pass);
+    return 0;
 }
 
-/* makes a null-terminated string lower-case. Changes CONTENTS! */
-static void
-lc(char *string)
+const char *
+make_challenge(char *domain, char *domain_controller)
+{
+    /* trying to circumvent some strange problem wih pointers in SMBLib */
+    /* Ugly as hell, but the lib is going to be dropped... */
+    strcpy(my_domain,domain);
+    strcpy(my_domain_controller,domain_controller);
+    if (init_challenge(my_domain, my_domain_controller) > 0) {
+        return NULL;
+    }
+    ntlm_challenge chal;
+    u_int32_t flags = NTLM_REQUEST_NON_NT_SESSION_KEY |
+                      NTLM_CHALLENGE_TARGET_IS_DOMAIN |
+                      NTLM_NEGOTIATE_ALWAYS_SIGN |
+                      NTLM_NEGOTIATE_USE_NTLM |
+                      NTLM_NEGOTIATE_USE_LM |
+                      NTLM_NEGOTIATE_ASCII;
+    ntlm_make_challenge(&chal, my_domain, my_domain_controller, (char *)challenge, NTLM_NONCE_LEN, flags);
+    int len = sizeof(chal) - sizeof(chal.payload) + le16toh(chal.target.maxlen);
+    return base64_encode_bin((char *)&chal, len);
+}
+
+/* returns NULL on failure, or a pointer to
+ * the user's credentials (domain\\username)
+ * upon success. WARNING. It's pointing to static storage.
+ * In case of problem sets as side-effect ntlm_errno to one of the
+ * codes defined in ntlm.h
+ */
+char *
+ntlm_check_auth(ntlm_authenticate * auth, int auth_length)
 {
-    char *p = string, c;
-    while ((c = *p)) {
-        *p = xtolower(c);
-        p++;
+    int rv;
+    char pass[MAX_PASSWD_LEN+1];
+    char *domain = credentials;
+    char *user;
+    lstring tmp;
+
+    if (handle == NULL) {	/*if null we aren't connected, but it shouldn't happen */
+        debug("Weird, we've been disconnected\n");
+        ntlm_errno = NTLM_ERR_NOT_CONNECTED;
+        return NULL;
+    }
+
+    /*      debug("fetching domain\n"); */
+    tmp = ntlm_fetch_string(&(auth->hdr), auth_length, &auth->domain, auth->flags);
+    if (tmp.str == NULL || tmp.l == 0) {
+        debug("No domain supplied. Returning no-auth\n");
+        ntlm_errno = NTLM_ERR_LOGON;
+        return NULL;
+    }
+    if (tmp.l > MAX_DOMAIN_LEN) {
+        debug("Domain string exceeds %d bytes, rejecting\n", MAX_DOMAIN_LEN);
+        ntlm_errno = NTLM_ERR_LOGON;
+        return NULL;
+    }
+    memcpy(domain, tmp.str, tmp.l);
+    user = domain + tmp.l;
+    *user++ = '\0';
+
+    /*      debug("fetching user name\n"); */
+    tmp = ntlm_fetch_string(&(auth->hdr), auth_length, &auth->user, auth->flags);
+    if (tmp.str == NULL || tmp.l == 0) {
+        debug("No username supplied. Returning no-auth\n");
+        ntlm_errno = NTLM_ERR_LOGON;
+        return NULL;
+    }
+    if (tmp.l > MAX_USERNAME_LEN) {
+        debug("Username string exceeds %d bytes, rejecting\n", MAX_USERNAME_LEN);
+        ntlm_errno = NTLM_ERR_LOGON;
+        return NULL;
     }
+    memcpy(user, tmp.str, tmp.l);
+    *(user + tmp.l) = '\0';
+
+
+    /* Authenticating against the NT response doesn't seem to work... */
+    tmp = ntlm_fetch_string(&(auth->hdr), auth_length, &auth->lmresponse, auth->flags);
+    if (tmp.str == NULL || tmp.l == 0) {
+        fprintf(stderr, "No auth at all. Returning no-auth\n");
+        ntlm_errno = NTLM_ERR_LOGON;
+        return NULL;
+    }
+    if (tmp.l > MAX_PASSWD_LEN) {
+        debug("Password string exceeds %d bytes, rejecting\n", MAX_PASSWD_LEN);
+        ntlm_errno = NTLM_ERR_LOGON;
+        return NULL;
+    }
+
+    memcpy(pass, tmp.str, tmp.l);
+    pass[min(MAX_PASSWD_LEN,tmp.l)] = '\0';
+
+#if 1
+    debug("Empty LM pass detection: user: '%s', ours:'%s', his: '%s' (length: %d)\n",
+          user,lmencoded_empty_pass,tmp.str,tmp.l);
+    if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
+        fprintf(stderr,"Empty LM password supplied for user %s\\%s. "
+                "No-auth\n",domain,user);
+        ntlm_errno=NTLM_ERR_LOGON;
+        return NULL;
+    }
+
+    tmp = ntlm_fetch_string(&(auth->hdr), auth_length, &auth->ntresponse, auth->flags);
+    if (tmp.str != NULL && tmp.l != 0) {
+        debug("Empty NT pass detection: user: '%s', ours:'%s', his: '%s' (length: %d)\n",
+              user,ntencoded_empty_pass,tmp.str,tmp.l);
+        if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
+            fprintf(stderr,"ERROR: Empty NT password supplied for user %s\\%s. No-auth\n", domain, user);
+            ntlm_errno = NTLM_ERR_LOGON;
+            return NULL;
+        }
+    }
+#endif
+
+    /* TODO: check against empty password!!!!! */
+
+
+    debug("checking domain: '%s', user: '%s', pass='%s'\n", domain, user, pass);
+
+    rv = SMB_Logon_Server(handle, user, pass, domain, 1);
+    debug("Login attempt had result %d\n", rv);
+
+    if (rv != NTLM_ERR_NONE) {	/* failed */
+        ntlm_errno = rv;
+        return NULL;
+    }
+    *(user - 1) = '\\';		/* hack. Performing, but ugly. */
+
+    debug("credentials: %s\n", credentials);
+    return credentials;
 }
 
+/* signal handler to be invoked when the authentication operation
+ * times out */
+static char got_timeout = 0;
+static void
+timeout_during_auth(int signum)
+{
+    dc_disconnect();
+}
 
 void
 send_bh_or_ld(char const *bhmessage, ntlm_authenticate * failedauth, int authlen)
 {
 #if NTLM_FAIL_OPEN
-    char *creds = NULL;
+    char user[NTLM_MAX_FIELD_LENGTH];
+    char domain[NTLM_MAX_FIELD_LENGTH];
     if (last_ditch_enabled) {
-        creds = fetch_credentials(failedauth, authlen);
-        if (creds) {
-            lc(creds);
-            SEND2("LD %s", creds);
+        user[0] = '\0';
+        domain[0] = '\0';
+        if (ntlm_unpack_auth(failedauth, user, domain, authlen) == 0) {
+            lc(domain);
+            lc(user);
+            SEND3("LD %s%s%s", domain, (domain[0]!='\0'?"//":""), user);
         } else {
             SEND("NA last-ditch on, but no credentials");
         }

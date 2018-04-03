         port = 0;
     }
 
-    s = static_cast<sockaddr_in_list *>(xcalloc(1, sizeof(*s)));
-    s->s.sin_port = htons(port);
-
     if (NULL == host)
-        s->s.sin_addr = any_addr;
-    else if (1 == safe_inet_addr(host, &s->s.sin_addr))
+        ipa.SetAnyAddr();
+    else if ( ipa.GetHostByName(host) )	/* dont use ipcache. Accept either FQDN or IPA. */
         (void) 0;
-    else if ((hp = gethostbyname(host)))	/* dont use ipcache */
-        s->s.sin_addr = inaddrFromHostent(hp);
     else
         self_destruct();
 
+    /* port MUST be set after the IPA lookup/conversion is perofrmed. */
+    ipa.SetPort(port);
+
     while (*head)
         head = &(*head)->next;
 
+    s = static_cast<IPAddress_list *>(xcalloc(1, sizeof(*s)));
+    s->s = ipa;
+
     *head = s;
 }
 
 static void
-parse_sockaddr_in_list(sockaddr_in_list ** head)
+parse_IPAddress_list(IPAddress_list ** head)
 {
     char *token;
 
     while ((token = strtok(NULL, w_space))) {
-        parse_sockaddr_in_list_token(head, token);
+        parse_IPAddress_list_token(head, token);
     }
 }
 
 static void
-dump_sockaddr_in_list(StoreEntry * e, const char *n, const sockaddr_in_list * s)
+dump_IPAddress_list(StoreEntry * e, const char *n, const IPAddress_list * s)
 {
+    char ntoabuf[MAX_IPSTRLEN];
+
     while (s) {
-        storeAppendPrintf(e, "%s %s:%d\n",
+        storeAppendPrintf(e, "%s %s\n",
                           n,
-                          inet_ntoa(s->s.sin_addr),
-                          ntohs(s->s.sin_port));
+                          s->s.NtoA(ntoabuf,MAX_IPSTRLEN));
         s = s->next;
     }
 }
 
 static void
-free_sockaddr_in_list(sockaddr_in_list ** head)
+free_IPAddress_list(IPAddress_list ** head)
 {
-    sockaddr_in_list *s;
-
-    while ((s = *head) != NULL) {
-        *head = s->next;
-        xfree(s);
-    }
+    if(*head) delete *head; *head = NULL;
 }
 
 #if CURRENTLY_UNUSED
 /* This code was previously used by http_port. Left as it really should
  * be used by icp_port and htcp_port
  */
 static int
-check_null_sockaddr_in_list(const sockaddr_in_list * s)
+check_null_IPAddress_list(const IPAdress_list * s)
 {
     return NULL == s;
 }

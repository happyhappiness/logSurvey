 
 /*      debug("fetching user name\n"); */
     tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->user);
-    if (tmp.str == NULL) {
+    if (tmp.str == NULL || tmp.l == 0) {
 	debug("No username supplied. Returning no-auth\n");
 	ntlm_errno = NTLM_LOGON_ERROR;
 	return NULL;
     }
     memcpy(user, tmp.str, tmp.l);
     *(user + tmp.l) = '\0';
 
+		
+		/* Authenticating against the NT response doesn't seem to work... */
+    tmp = ntlm_fetch_string((char *) auth, auth_length, &auth->lmresponse);
+    if (tmp.str == NULL || tmp.l == 0) {
+	fprintf(stderr, "No auth at all. Returning no-auth\n");
+	ntlm_errno = NTLM_LOGON_ERROR;
+	return NULL;
+    }
+		
+    memcpy(pass, tmp.str, tmp.l);
+    pass[25] = '\0';
+
+#if 1
+		debug ("Empty LM pass detection: user: '%s', ours:'%s', his: '%s'"
+					 "(length: %d)\n",
+					 user,lmencoded_empty_pass,tmp.str,tmp.l);
+		if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
+			fprintf(stderr,"Empty LM password supplied for user %s\\%s. "
+							"No-auth\n",domain,user);
+			ntlm_errno=NTLM_LOGON_ERROR;
+			return NULL;
+		}
+		
+		tmp = ntlm_fetch_string ((char *) auth, auth_length, &auth->ntresponse);
+		if (tmp.str != NULL && tmp.l != 0) {
+			debug ("Empty NT pass detection: user: '%s', ours:'%s', his: '%s'"
+						 "(length: %d)\n",
+						 user,ntencoded_empty_pass,tmp.str,tmp.l);
+			if (memcmp(tmp.str,lmencoded_empty_pass,ENCODED_PASS_LEN)==0) {
+				fprintf(stderr,"Empty NT password supplied for user %s\\%s. "
+								"No-auth\n",domain,user);
+				ntlm_errno=NTLM_LOGON_ERROR;
+				return NULL;
+			}
+		}
+#endif
+
+		/* TODO: check against empty password!!!!! */
+		
+
+
     debug("checking domain: '%s', user: '%s', pass='%s'\n", domain, user, pass);
 
     rv = SMB_Logon_Server(handle, user, pass, domain, 1);

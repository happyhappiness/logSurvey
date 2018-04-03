         ntlm_request->authserver = NULL;
         debug(29, 4) ("authenticateNTLMHandleReply: Error validating user via NTLM. Error returned '%s'\n", reply);
         ntlm_request->auth_state = AUTHENTICATE_STATE_FAILED;
+        reply += 3;
 
-        if ((t = strchr(reply, ' ')))	/* strip after a space */
-            *t = '\0';
+        if (*reply)
+            auth_user_request->setDenyMessage(reply);
     } else if (strncasecmp(reply, "NA", 2) == 0) {
         /* NTLM Helper protocol violation! */
         fatal("NTLM Helper returned invalid response \"NA\" - a error message MUST be attached\n");

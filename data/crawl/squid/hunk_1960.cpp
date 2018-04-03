         safe_free(lm_request->server_blob);
         lm_request->releaseAuthServer();
         debugs(29, DBG_IMPORTANT, "ERROR: NTLM Authentication validating user. Error returned '" << reply << "'");
-    } else {
-        /* protocol error */
-        fatalf("authenticateNTLMHandleReply: *** Unsupported helper response ***, '%s'\n", reply);
+        break;
     }
 
     if (lm_request->request) {

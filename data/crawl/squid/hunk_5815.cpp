 	r->data = data;
 	r->auth_user_request = auth_user_request;
 	snprintf(buf, 8192, "KK %s\n", sent_string);
-	helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, ntlm_request->authhelper);
+	/* getting rid of deferred request status */
+	ntlm_request->authserver_deferred = 0;
+	helperStatefulSubmit(ntlmauthenticators, buf, authenticateNTLMHandleReply, r, ntlm_request->authserver);
 	debug(29, 9) ("authenticateNTLMstart: finished\n");
 	break;
     default:
 	fatal("Invalid authenticate state for NTLMStart");
     }
-#endif
 }
 
 /* callback used by stateful helper routines */

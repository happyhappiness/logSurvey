 	/* set these to now because this is either a new login from an 
 	 * existing user or a new user */
 	auth_user->expiretime = current_time.tv_sec;
-	ntlm_request->flags.credentials_ok = 1;		/*authenticated ok */
 	return;
 	break;
     case AUTHENTICATE_STATE_DONE:
 	fatal("authenticateNTLMAuthenticateUser: unexpect auth state DONE! Report a bug to the squid developers.\n");
+	break;
+    case AUTHENTICATE_STATE_FAILED:
+	/* we've failed somewhere in authentication */
+	debug(29, 9) ("authenticateNTLMAuthenticateUser: auth state ntlm failed. %s\n", proxy_auth);
+	return;
     }
-
     return;
 }

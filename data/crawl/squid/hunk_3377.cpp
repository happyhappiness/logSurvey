         HTTPMSGLOCK(request);
         break;
 
-    case AUTHENTICATE_STATE_DONE:
+    case AuthUser::Ok:
         fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
         break;
 
-    case AUTHENTICATE_STATE_FAILED:
+    case AuthUser::Failed:
         /* we've failed somewhere in authentication */
         debugs(29, 9, "AuthNTLMUserRequest::authenticate: auth state ntlm failed. " << proxy_auth);
         break;

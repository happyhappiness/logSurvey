         HTTPMSGLOCK(request);
         break;
 
-    case AuthUser::Ok:
+    case Auth::Ok:
         fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
         break;
 
-    case AuthUser::Failed:
+    case Auth::Failed:
         /* we've failed somewhere in authentication */
         debugs(29, 9, "AuthNTLMUserRequest::authenticate: auth state ntlm failed. " << proxy_auth);
         break;

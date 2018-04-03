         break;
 
     case Auth::Ok:
-        fatal("AuthNegotiateUserRequest::authenticate: unexpected auth state DONE! Report a bug to the squid developers.\n");
+        fatal("Auth::Negotiate::UserRequest::authenticate: unexpected auth state DONE! Report a bug to the squid developers.\n");
         break;
 
     case Auth::Failed:

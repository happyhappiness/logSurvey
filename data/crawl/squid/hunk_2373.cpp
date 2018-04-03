         break;
 
     case Auth::Ok:
-        fatal("AuthNTLMUserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
+        fatal("Auth::Ntlm::UserRequest::authenticate: unexpect auth state DONE! Report a bug to the squid developers.\n");
         break;
 
     case Auth::Failed:

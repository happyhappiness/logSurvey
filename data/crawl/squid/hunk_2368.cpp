 }
 
 void
-AuthUserRequest::addAuthenticationInfoHeader(HttpReply * rep, int accelerated)
+Auth::UserRequest::addAuthenticationInfoHeader(HttpReply * rep, int accelerated)
 {}
 
 void
-AuthUserRequest::addAuthenticationInfoTrailer(HttpReply * rep, int accelerated)
+Auth::UserRequest::addAuthenticationInfoTrailer(HttpReply * rep, int accelerated)
 {}
 
 void
-AuthUserRequest::onConnectionClose(ConnStateData *)
+Auth::UserRequest::onConnectionClose(ConnStateData *)
 {}
 
 const char *
-AuthUserRequest::connLastHeader()
+Auth::UserRequest::connLastHeader()
 {
-    fatal("AuthUserRequest::connLastHeader should always be overridden by conn based auth schemes");
+    fatal("Auth::UserRequest::connLastHeader should always be overridden by conn based auth schemes");
     return NULL;
 }
 

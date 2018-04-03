 
     if ((static_cast<Auth::Digest::Config*>(Auth::Config::Find("digest"))->authenticateProgram) && authDigestNonceLastRequest(nonce)) {
         flags.authinfo_sent = 1;
-        debugs(29, 9, "authDigestAddHead: Sending type:" << type << " header: 'nextnonce=\"" << authenticateDigestNonceNonceb64(nonce) << "\"");
+        debugs(29, 9, HERE << "Sending type:" << type << " header: 'nextnonce=\"" << authenticateDigestNonceNonceb64(nonce) << "\"");
         httpHeaderPutStrf(&rep->header, type, "nextnonce=\"%s\"", authenticateDigestNonceNonceb64(nonce));
     }
 }
 
 #if WAITING_FOR_TE
 void
-AuthDigestUserRequest::addAuthenticationInfoTrailer(HttpReply * rep, int accel)
+Auth::Digest::UserRequest::addAuthenticationInfoTrailer(HttpReply * rep, int accel)
 {
     int type;
 

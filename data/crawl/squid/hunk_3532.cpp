 }
 
 void
-AuthBasicConfig::fixHeader(AuthUserRequest *auth_user_request, HttpReply *rep, http_hdr_type type, HttpRequest * request)
+AuthBasicConfig::fixHeader(AuthUserRequest *auth_user_request, HttpReply *rep, http_hdr_type hdrType, HttpRequest * request)
 {
     if (authenticate) {
-        debugs(29, 9, HERE << "Sending type:" << type << " header: 'Basic realm=\"" << basicAuthRealm << "\"'");
-        httpHeaderPutStrf(&rep->header, type, "Basic realm=\"%s\"", basicAuthRealm);
+        debugs(29, 9, HERE << "Sending type:" << hdrType << " header: 'Basic realm=\"" << basicAuthRealm << "\"'");
+        httpHeaderPutStrf(&rep->header, hdrType, "Basic realm=\"%s\"", basicAuthRealm);
     }
 }
 

 
     /* New request, no user details */
     if (auth_user_request == NULL) {
-        debugs(29, 9, "AuthNTLMConfig::fixHeader: Sending type:" << type << " header: 'NTLM'");
-        httpHeaderPutStrf(&rep->header, type, "NTLM");
+        debugs(29, 9, "AuthNTLMConfig::fixHeader: Sending type:" << hdrType << " header: 'NTLM'");
+        httpHeaderPutStrf(&rep->header, hdrType, "NTLM");
 
         if (!keep_alive) {
             /* drop the connection */

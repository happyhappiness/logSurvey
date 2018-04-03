     httpBuf.clean();
 }
 
-void ICAPModXact::makeUsernameHeader(const HttpRequest *request, MemBuf &buf)
+void Adaptation::Icap::ModXact::makeUsernameHeader(const HttpRequest *request, MemBuf &buf)
 {
     if (const AuthUserRequest *auth = request->auth_user_request) {
         if (char const *name = auth->username()) {
-            const char *value = TheICAPConfig.client_username_encode ?
+            const char *value = TheConfig.client_username_encode ?
                                 base64_encode(name) : name;
-            buf.Printf("%s: %s\r\n", TheICAPConfig.client_username_header,
+            buf.Printf("%s: %s\r\n", TheConfig.client_username_header,
                        value);
         }
     }
 }
 
-void ICAPModXact::encapsulateHead(MemBuf &icapBuf, const char *section, MemBuf &httpBuf, const HttpMsg *head)
+void Adaptation::Icap::ModXact::encapsulateHead(MemBuf &icapBuf, const char *section, MemBuf &httpBuf, const HttpMsg *head)
 {
     // update ICAP header
     icapBuf.Printf("%s=%d, ", section, (int) httpBuf.contentSize());

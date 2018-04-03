 
 void Adaptation::Icap::ModXact::makeUsernameHeader(const HttpRequest *request, MemBuf &buf)
 {
+#if USE_AUTH
     if (request->auth_user_request != NULL) {
         char const *name = request->auth_user_request->username();
         if (name) {
             const char *value = TheConfig.client_username_encode ? base64_encode(name) : name;
             buf.Printf("%s: %s\r\n", TheConfig.client_username_header, value);
         }
     }
+#endif
 }
 
 void Adaptation::Icap::ModXact::encapsulateHead(MemBuf &icapBuf, const char *section, MemBuf &httpBuf, const HttpMsg *head)

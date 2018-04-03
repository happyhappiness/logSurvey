     return NULL;
 }
 
-extern string httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
+extern String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
 {
     fatal ("dummy function\n");
-    return "";
+    return String();
 }
 
 SQUIDCEXTERN int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type)

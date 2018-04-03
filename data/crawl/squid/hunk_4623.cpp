     return NULL;
 }
 
-extern String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
+extern string httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
 {
     fatal ("dummy function\n");
-    return String();
+    return "";
 }
 
 SQUIDCEXTERN int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type)

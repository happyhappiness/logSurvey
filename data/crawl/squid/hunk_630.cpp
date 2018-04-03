     return NULL;
 }
 
-String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id)
+String httpHeaderGetList(const HttpHeader * hdr, Http::HdrType id)
 {
     fatal ("dummy function\n");
     return String();
 }
 
-int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type)
+int httpHeaderHas(const HttpHeader * hdr, Http::HdrType type)
 {
     fatal ("dummy function\n");
     return 0;

 #endif
 
     /* Append X-Cache */
-    httpHeaderPutStrf(hdr, HDR_X_CACHE, "%s from %s",
+    httpHeaderPutStrf(hdr, Http::HdrType::X_CACHE, "%s from %s",
                       is_hit ? "HIT" : "MISS", getMyHostname());
 
 #if USE_CACHE_DIGESTS
     /* Append X-Cache-Lookup: -- temporary hack, to be removed @?@ @?@ */
-    httpHeaderPutStrf(hdr, HDR_X_CACHE_LOOKUP, "%s from %s:%d",
+    httpHeaderPutStrf(hdr, Http::HdrType::X_CACHE_LOOKUP, "%s from %s:%d",
                       lookup_type ? lookup_type : "NONE",
                       getMyHostname(), getMyPort());
 

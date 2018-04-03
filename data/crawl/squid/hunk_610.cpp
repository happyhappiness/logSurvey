          * might want to know. Someone _will_ want to know OTOH, the first
          * X-CACHE-MISS entry should tell us who.
          */
-        httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%s %d", name, xerrno);
+        httpHeaderPutStrf(&rep->header, Http::HdrType::X_SQUID_ERROR, "%s %d", name, xerrno);
 
 #if USE_ERR_LOCALES
         /*

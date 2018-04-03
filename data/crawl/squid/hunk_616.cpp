     /* append Via */
     if (Config.onoff.via) {
         String strVia;
-        strVia = hdr_in->getList(HDR_VIA);
+        strVia = hdr_in->getList(Http::HdrType::VIA);
         snprintf(bbuf, BBUF_SZ, "%d.%d %s",
                  request->http_ver.major,
                  request->http_ver.minor, ThisCache);
         strListAdd(&strVia, bbuf, ',');
-        hdr_out->putStr(HDR_VIA, strVia.termedBuf());
+        hdr_out->putStr(Http::HdrType::VIA, strVia.termedBuf());
         strVia.clean();
     }
 
     if (request->flags.accelerated) {
         /* Append Surrogate-Capabilities */
-        String strSurrogate(hdr_in->getList(HDR_SURROGATE_CAPABILITY));
+        String strSurrogate(hdr_in->getList(Http::HdrType::SURROGATE_CAPABILITY));
 #if USE_SQUID_ESI
         snprintf(bbuf, BBUF_SZ, "%s=\"Surrogate/1.0 ESI/1.0\"", Config.Accel.surrogate_id);
 #else
         snprintf(bbuf, BBUF_SZ, "%s=\"Surrogate/1.0\"", Config.Accel.surrogate_id);
 #endif
         strListAdd(&strSurrogate, bbuf, ',');
-        hdr_out->putStr(HDR_SURROGATE_CAPABILITY, strSurrogate.termedBuf());
+        hdr_out->putStr(Http::HdrType::SURROGATE_CAPABILITY, strSurrogate.termedBuf());
     }
 
     /** \pre Handle X-Forwarded-For */
     if (strcmp(opt_forwarded_for, "delete") != 0) {
 
-        String strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);
+        String strFwd = hdr_in->getList(Http::HdrType::X_FORWARDED_FOR);
 
         if (strFwd.size() > 65536/2) {
             // There is probably a forwarding loop with Via detection disabled.

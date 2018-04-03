 
         break;
 
-    case HDR_HOST:
+    case Http::HdrType::HOST:
         /** \par Host:
          * Normally Squid rewrites the Host: header.
          * However, there is one case when we don't: If the URL
          * went through our redirector and the admin configured
          * 'redir_rewrites_host' to be off.
          */
         if (request->peer_domain)
-            hdr_out->putStr(HDR_HOST, request->peer_domain);
+            hdr_out->putStr(Http::HdrType::HOST, request->peer_domain);
         else if (request->flags.redirected && !Config.onoff.redir_rewrites_host)
             hdr_out->addEntry(e->clone());
         else {
             SBuf authority = request->url.authority();
-            hdr_out->putStr(HDR_HOST, authority.c_str());
+            hdr_out->putStr(Http::HdrType::HOST, authority.c_str());
         }
 
         break;
 
-    case HDR_IF_MODIFIED_SINCE:
+    case Http::HdrType::IF_MODIFIED_SINCE:
         /** \par If-Modified-Since:
          * append unless we added our own,
          * but only if cache_miss_revalidate is enabled, or

 
     case HDR_HOST:
         /*
-         * Normally Squid does not copy the Host: header from
-         * a client request into the forwarded request headers.
-         * However, there is one case when we do: If the URL
+         * Normally Squid rewrites the Host: header.
+         * However, there is one case when we don't: If the URL
          * went through our redirector and the admin configured
          * 'redir_rewrites_host' to be off.
          */
 
-        if (request->flags.redirected)
-            if (!Config.onoff.redir_rewrites_host)
-                httpHeaderAddEntry(hdr_out, httpHeaderEntryClone(e));
+        if (request->flags.redirected && !Config.onoff.redir_rewrites_host)
+            httpHeaderAddEntry(hdr_out, httpHeaderEntryClone(e));
+        else {
+            /* use port# only if not default */
+
+            if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
+                httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->host);
+            } else {
+                httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
+                                  orig_request->host, (int) orig_request->port);
+            }
+        }
 
         break;
 
     case HDR_IF_MODIFIED_SINCE:
         /* append unless we added our own;
          * note: at most one client's ims header can pass through */
+
         if (!httpHeaderHas(hdr_out, HDR_IF_MODIFIED_SINCE))
             httpHeaderAddEntry(hdr_out, httpHeaderEntryClone(e));
 
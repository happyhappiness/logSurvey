         rep->setHeaders(version, HTTP_MOVED_TEMPORARILY, NULL, "text/html", 0, 0, -1);
 
         if (request) {
-            char *quoted_url = rfc1738_escape_part(urlCanonical(request));
-            httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
+            MemBuf redirect_location;
+            redirect_location.init();
+            DenyInfoLocation(name, request, redirect_location);
+            httpHeaderPutStrf(&rep->header, HDR_LOCATION, "%s", redirect_location.content() );
         }
 
         httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s", httpStatus, "Access Denied");

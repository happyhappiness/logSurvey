         if (request) {
             MemBuf redirect_location;
             redirect_location.init();
-            DenyInfoLocation(name, request, redirect_location);
+            DenyInfoLocation(name, request.getRaw(), redirect_location);
             httpHeaderPutStrf(&rep->header, Http::HdrType::LOCATION, "%s", redirect_location.content() );
         }
 

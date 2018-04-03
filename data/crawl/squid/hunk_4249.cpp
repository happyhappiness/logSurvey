         break;
 
     case 'p':
-        if (r) {
-            mb.Printf("%d", (int) r->port);
+        if (request) {
+            mb.Printf("%d", (int) request->port);
         } else {
             p = "[unknown port]";
         }
 
         break;
 
     case 'P':
-        p = r ? ProtocolStr[r->protocol] : "[unknown protocol]";
+        p = request ? ProtocolStr[request->protocol] : "[unknown protocol]";
         break;
 
     case 'R':
 
-        if (NULL != r) {
+        if (NULL != request) {
             Packer p;
             mb.Printf("%s %s HTTP/%d.%d\n",
-                      RequestMethodStr(r->method),
-                      r->urlpath.size() ? r->urlpath.buf() : "/",
-                      r->http_ver.major, r->http_ver.minor);
+                      RequestMethodStr(request->method),
+                      request->urlpath.size() ? request->urlpath.buf() : "/",
+                      request->http_ver.major, request->http_ver.minor);
             packerToMemInit(&p, &mb);
-            r->header.packInto(&p);
+            request->header.packInto(&p);
             packerClean(&p);
-        } else if (err->request_hdrs) {
-            p = err->request_hdrs;
+        } else if (request_hdrs) {
+            p = request_hdrs;
         } else {
             p = "[no request]";
         }

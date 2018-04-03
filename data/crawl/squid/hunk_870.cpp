     mb.init();
 
     if (request->errType != ERR_NONE)
-        mb.Printf("%i-%s\r\n", scode, errorPageName(request->errType));
+        mb.appendf("%i-%s\r\n", scode, errorPageName(request->errType));
 
     if (request->errDetail > 0) {
         // XXX: > 0 may not always mean that this is an errno
-        mb.Printf("%i-Error: (%d) %s\r\n", scode,
+        mb.appendf("%i-Error: (%d) %s\r\n", scode,
                   request->errDetail,
                   strerror(request->errDetail));
     }

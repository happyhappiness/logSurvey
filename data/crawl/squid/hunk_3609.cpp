 {
     static char buf[1024];
     safe_free(req->pub_auth);
-    debug(3) fprintf(stderr, "cmgr: encoding for pub...\n");
+    debug("cmgr: encoding for pub...\n");
 
     if (!req->passwd || !strlen(req->passwd))
         return;

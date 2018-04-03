                  req->hostname,
                  req->action,
                  make_auth_header(req));
-    write(s, buf, l);
-    debug(1) fprintf(stderr, "wrote request: '%s'\n", buf);
+    if (write(s, buf, l) <0 )
+        debug(1) fprintf(stderr, "ERROR: (%d) writing request: '%s'\n", errno, buf);
+    else
+        debug(1) fprintf(stderr, "wrote request: '%s'\n", buf);
     return read_reply(s, req);
 }
 

 void
 HttpRequest::clean()
 {
-    if (body_connection.getRaw() != NULL)
-        fatal ("request being destroyed with body connection intact\n");
+    if (body_reader != NULL)
+        fatal ("request being destroyed with body reader intact\n");
 
     if (auth_user_request) {
         auth_user_request->unlock();

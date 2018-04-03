 void
 HttpRequest::clean()
 {
-    if (body_reader != NULL)
-        fatal ("request being destroyed with body reader intact\n");
+    // we used to assert that the pipe is NULL, but now the request only 
+    // points to a pipe that is owned and initiated by another object.
+    body_pipe = NULL; 
 
     if (auth_user_request) {
         auth_user_request->unlock();

     return req;
 }
 
+void HttpRequest::reset()
+{
+    clean();
+    *this = HttpRequest(); // XXX: ugly; merge with clean()
+}
+
 void
 requestDestroy(HttpRequest * req)
 {
     assert(req);
+    req->clean();
+    delete req;
+}
 
-    if (req->body_connection.getRaw() != NULL)
+// note: this is a very low-level method that leaves us in inconsistent state
+// suitable for deletion or assignment only; XXX: should be merged with reset()
+void HttpRequest::clean()
+{
+    if (body_connection.getRaw() != NULL)
         fatal ("request being destroyed with body connection intact\n");
 
-    if (req->auth_user_request)
-        req->auth_user_request->unlock();
+    if (auth_user_request)
+        auth_user_request->unlock();
 
-    safe_free(req->canonical);
+    safe_free(canonical);
 
-    safe_free(req->vary_headers);
+    safe_free(vary_headers);
 
-    req->urlpath.clean();
+    urlpath.clean();
 
-    httpHeaderClean(&req->header);
+    httpHeaderClean(&header);
 
-    if (req->cache_control)
-        httpHdrCcDestroy(req->cache_control);
+    if (cache_control)
+        httpHdrCcDestroy(cache_control);
 
-    if (req->range)
-        delete req->range;
+    if (range)
+        delete range;
 
-    req->tag.clean();
+    tag.clean();
 
-    req->extacl_user.clean();
+    extacl_user.clean();
 
-    req->extacl_passwd.clean();
+    extacl_passwd.clean();
 
-    req->extacl_log.clean();
+    extacl_log.clean();
+}
 
-    delete req;
+bool HttpRequest::sanityCheckStartLine(MemBuf *buf, http_status *error)
+{
+    /*
+     * Just see if the request buffer starts with a known
+     * HTTP request method.  NOTE this whole function is somewhat
+     * superfluous and could just go away.
+     */
+
+    if (METHOD_NONE == urlParseMethod(buf->content())) {
+        debug(73, 3)("HttpRequest::sanityCheckStartLine: did not find HTTP request method\n");
+        return false;
+    }
+
+    return true;
+}
+
+bool HttpRequest::parseRequestLine(const char *start, const char *end)
+{
+    fatal("HttpRequest::parseRequestLine not implemented yet");
+    return false;
 }
 
 HttpRequest *

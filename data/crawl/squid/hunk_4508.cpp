 }
 
 bool
-HttpRequest::expectingBody(method_t unused, ssize_t&) const
+HttpRequest::expectingBody(method_t unused, int64_t&) const
 {
     fatal("Not implemented");
     return false;

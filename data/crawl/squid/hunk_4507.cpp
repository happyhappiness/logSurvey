 }
 
 bool
-HttpReply::expectingBody(method_t, ssize_t&) const
+HttpReply::expectingBody(method_t, int64_t&) const
 {
     fatal ("Not implemented");
     return false;

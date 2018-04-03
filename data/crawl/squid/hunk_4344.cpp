     fatal ("Not implemented.");
 }
 
-void
-HttpReply::absorb(HttpReply * new_rep)
-{
-    fatal ("Not implemented");
-}
-
 void
 HttpReply::setHeaders(HttpVersion ver, http_status status, const char *reason,
                       const char *ctype, int64_t clen, time_t lmt, time_t expires)

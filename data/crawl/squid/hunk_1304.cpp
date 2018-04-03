     return lowAppend(S, Ssize);
 }
 
+SBuf &
+SBuf::append(const char c)
+{
+    return lowAppend(&c, 1);
+}
+
 SBuf&
 SBuf::Printf(const char *fmt, ...)
 {

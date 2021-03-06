     *buf = 0;
     int x;
 
+#ifdef VA_COPY
+    va_args ap;
+    /* Fix of bug 753r. The value of vargs is undefined
+     * after vsnprintf() returns. Make a copy of vargs
+     * incase we loop around and call vsnprintf() again.
+     */
+    VA_COPY(ap,vargs);
+    errno = 0;
+    if ((x = vsnprintf(buf, sizeof(buf), fmt, ap)) < 0) {
+        fatalf( xstrerror(errno));
+        return;
+    }
+    va_end(ap);
+#else /* VA_COPY */
     errno = 0;
     if ((x = vsnprintf(buf, sizeof(buf), fmt, vargs)) < 0) {
         fatalf( xstrerror(errno));
         return;
     }
+#endif /*VA_COPY*/
 
     if (x < sizeof(buf)) {
         append(buf, x);
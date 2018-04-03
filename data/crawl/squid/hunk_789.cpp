     VA_COPY(ap,vargs);
     errno = 0;
     if ((x = vsnprintf(buf, sizeof(buf), fmt, ap)) < 0) {
-        fatalf( xstrerror(errno));
+        fatal(xstrerr(errno));
         return;
     }
     va_end(ap);
 #else /* VA_COPY */
     errno = 0;
     if ((x = vsnprintf(buf, sizeof(buf), fmt, vargs)) < 0) {
-        fatalf( xstrerror(errno));
+        fatal(xstrerr(errno));
         return;
     }
 #endif /*VA_COPY*/
 
-    if (x < sizeof(buf)) {
+    if (x < static_cast<int>(sizeof(buf))) {
         append(buf, x);
         return;
     }
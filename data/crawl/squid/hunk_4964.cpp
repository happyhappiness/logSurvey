 
     void terminate(); // zero-terminates the buffer w/o increasing contentSize
 
+    /* init with specific sizes */
+    void init(mb_size_t szInit, mb_size_t szMax);
+
+    /* init with defaults */
+    void init();
+
+    /* cleans mb; last function to call if you do not give .buf away */
+    void clean();
+
+    /* resets mb preserving (or initializing if needed) memory buffer */
+    void reset();
+
+    /* unfirtunate hack to test if the buffer has been Init()ialized */
+    int isNull();
+
+    /* calls snprintf, extends buffer if needed */
+    /* note we use Printf instead of printf so the compiler won't */
+    /* think we're calling the libc printf() */
+#if STDC_HEADERS
+
+    void Printf(const char *fmt,...) PRINTF_FORMAT_ARG2;
+#else
+
+    void Printf();
+#endif
+
+    /* vPrintf for other printf()'s to use */
+    void vPrintf(const char *fmt, va_list ap);
+
+    /* returns free() function to be used, _freezes_ the object! */
+    FREE *freeFunc();
+
+
 private:
     /*
      * private copy constructor and assignment operator generates

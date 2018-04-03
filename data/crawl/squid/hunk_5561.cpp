     if (tracefp && s)
 	fprintf(tracefp, "f:%p\n", s);
 #endif
+    PROF_stop(xfree);
 }
 
 /* xxfree() - like xfree(), but we already know s != NULL */
 void
 xxfree(const void *s_const)
 {
-    void *s = (void *) s_const;
+    void *s = (void *)s_const;
+    PROF_start(xxfree);
 #if XMALLOC_TRACE
     xmalloc_show_trace(s, -1);
 #endif

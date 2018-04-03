     if (tracefp && s)
 	fprintf(tracefp, "f:%p\n", s);
 #endif
+    PROF_stop(xxfree);
 }
 
 /*

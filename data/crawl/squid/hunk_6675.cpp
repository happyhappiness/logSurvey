     xmalloc_show_trace(p, 1);
 #endif
 #if MEM_GEN_TRACE
-	fprintf(tracefp,"c:%d:%d:%x\n", n, sz,p);
+	fprintf(tracefp,"c:%d:%d:%p\n", n, sz,p);
 #endif
     return (p);
 }
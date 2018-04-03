 #endif
 #if MEM_GEN_TRACE
     if (tracefp)
-	fprintf(tracefp, "c:%u:%u:%p\n", (unsigned int)n, (unsigned int)sz, p);
+	fprintf(tracefp, "c:%u:%u:%p\n", (unsigned int) n, (unsigned int) sz, p);
 #endif
     return (p);
 }

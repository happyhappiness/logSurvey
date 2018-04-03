 #endif
     free(s);
 #if MEM_GEN_TRACE
-    fprintf(tracefp,"f:%x\n",s);
+    fprintf(tracefp,"f:%p\n",s);
 #endif
 }
 

                 fatal("Need to add -DMALLOC_DBG when compiling to use -mX option");
 #endif
 
-            } else {
-#if XMALLOC_TRACE
-                xmalloc_trace = !xmalloc_trace;
-#else
-                fatal("Need to configure --enable-xmalloc-debug-trace to use -m option");
-#endif
-            }
+            } 
             break;
 
         case 'n':

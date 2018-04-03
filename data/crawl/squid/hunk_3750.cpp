 debug(char *format,...)
 {
 }
-
 #endif
-
+#endif /* debug already defined */
 
 /* A couple of harmless helper macros */
 #define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");

 
     printf("\n</PRE>\n");
     print_trailer();
-    (void) close(conn);
+    close(conn);
     exit(0);
     /* NOTREACHED */
     return 0;

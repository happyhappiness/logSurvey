 
   fh = fopen(file, "r");
   if (fh == NULL) {
-    char errbuf[1024];
     fprintf(stderr, "Failed to open types database `%s': %s.\n", file,
-            sstrerror(errno, errbuf, sizeof(errbuf)));
-    ERROR("Failed to open types database `%s': %s", file,
-          sstrerror(errno, errbuf, sizeof(errbuf)));
+            STRERRNO);
+    ERROR("Failed to open types database `%s': %s", file, STRERRNO);
     return -1;
   }
 

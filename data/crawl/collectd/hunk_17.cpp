 
     if ((pid = fork()) == -1) {
       /* error */
-      char errbuf[1024];
-      fprintf(stderr, "fork: %s", sstrerror(errno, errbuf, sizeof(errbuf)));
+      fprintf(stderr, "fork: %s", STRERRNO);
       return 1;
     } else if (pid != 0) {
       /* parent */

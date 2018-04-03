     sigemptyset(&sa.sa_mask);
 
     if (sigaction(SIGPIPE, &sa, NULL) < 0) {
-        fprintf(stderr, "Cannot set PIPE signal.\n");
-        exit(-1);
+	fprintf(stderr, "Cannot set PIPE signal.\n");
+	exit(-1);
     }
-
 #else
     signal(SIGPIPE, pipe_handler);
 

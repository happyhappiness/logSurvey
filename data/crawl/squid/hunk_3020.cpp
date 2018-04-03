     }
 
     if (opt_verbose)
-        fprintf(stderr, "Request: '%s'\n", msg);
+        fprintf(stderr, "Request:'%s'\n", msg);
 
     if (ping) {
 #if HAVE_SIGACTION

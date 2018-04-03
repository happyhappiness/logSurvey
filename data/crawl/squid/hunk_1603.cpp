         strcat(msg, "\r\n");
     }
 
-    if (opt_verbose)
-        fprintf(stderr, "Request:'%s'\n", msg);
+    debugVerbose(1, "Request:" << std::endl << msg << std::endl << ".");
 
     if (ping) {
 #if HAVE_SIGACTION

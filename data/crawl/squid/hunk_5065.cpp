 {
     fprintf(stderr,
 #if USE_WIN32_SERVICE
-            "Usage: %s [-cdhirsvzCDFNRVYX] [-f config-file] [-[au] port] [-k signal] [-n name] [-O CommandLine]\n"
+            "Usage: %s [-cdhirvzCDFNRVYX] [-s | -l facility] [-f config-file] [-[au] port] [-k signal] [-n name] [-O CommandLine]\n"
 #else
-            "Usage: %s [-cdhsvzCDFNRVYX] [-f config-file] [-[au] port] [-k signal]\n"
+            "Usage: %s [-cdhvzCDFNRVYX] [-s | -l facility] [-f config-file] [-[au] port] [-k signal]\n"
 #endif
             "       -a port   Specify HTTP port number (default: %d).\n"
             "       -d level  Write debugging to stderr also.\n"

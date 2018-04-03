 #if HAVE_SYS_STAT_H
             struct stat dstat;
 #endif
-	    if (optarg)
+            if (optarg)
                 rcache_dir = xstrdup(optarg);
-	    else {
+            else {
                 fprintf(stderr, "ERROR: replay cache directory not given\n");
-		exit(1);
-	    }
+                exit(1);
+            }
             /*
              * Some sanity checks
              */

 #endif
             break;
         case 't':
-	    if (optarg)
+            if (optarg)
                 rcache_type = xstrdup(optarg);
-	    else {
+            else {
                 fprintf(stderr, "ERROR: replay cache type not given\n");
-		exit(1);
-	    }
+                exit(1);
+            }
             break;
         case 's':
-	    if (optarg)
+            if (optarg)
                 service_principal = xstrdup(optarg);
-	    else {
+            else {
                 fprintf(stderr, "ERROR: service principal not given\n");
-		exit(1);
-	    }
+                exit(1);
+            }
             break;
         default:
             fprintf(stderr, "Usage: \n");

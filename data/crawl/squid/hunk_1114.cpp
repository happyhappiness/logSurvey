             } else {
                 fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
             }
-            // fall through to display help texts.
+        // fall through to display help texts.
 
         default:
             usage(argv[0]);

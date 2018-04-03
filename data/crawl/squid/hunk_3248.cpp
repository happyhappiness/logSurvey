             opt = optopt;
             /* fall thru to default */
         default:
-            fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
+            fprintf(stderr, "ERROR: unknown option: -%c. Exiting\n", opt);
             usage();
             had_error = 1;
         }

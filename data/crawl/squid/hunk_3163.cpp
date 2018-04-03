             }
         } else {
             result = 0;
-            fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
+            fprintf(stderr, "%s: ERROR: NetUserGetGroups() failed.'\n", program_name);
         }
     } else {
-        fprintf(stderr, "%s Can't find DC for local domain '%s'\n", myname, machinedomain);
+        fprintf(stderr, "%s: ERROR: Can't find DC for local domain '%s'\n", program_name, machinedomain);
     }
     /*
      * Free the allocated memory.

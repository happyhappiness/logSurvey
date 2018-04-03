                     else
                       {
                         /* A normal makefile.  We must die later.  */
-                        error (NILF, "Makefile `%s' was not found", dep_name (d));
+                        error (NILF, "Makefile `%s' was not found",
+                               dep_name (d));
                         any_failed = 1;
                       }
                   }
+            /* Reset this to empty so we get the right error message below.  */
+            read_makefiles = 0;
 
 	    if (any_remade)
 	      goto re_exec;

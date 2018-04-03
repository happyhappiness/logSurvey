                     if (d->changed & RM_INCLUDED)
                       /* An included makefile.  We don't need
                          to die, but we do want to complain.  */
-                      error ("Included makefile `%s' was not found.",
+                      error (NILF, "Included makefile `%s' was not found.",
                              dep_name (d));
                     else
                       {
                         /* A normal makefile.  We must die later.  */
-                        error ("Makefile `%s' was not found", dep_name (d));
+                        error (NILF, "Makefile `%s' was not found", dep_name (d));
                         any_failed = 1;
                       }
                   }

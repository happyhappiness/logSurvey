                   /* This makefile was not found at all.  */
                   if (! (d->changed & RM_DONTCARE))
                     {
+                      const char *dnm = dep_name (d);
+                      size_t l = strlen (dnm);
+
                       /* This is a makefile we care about.  See how much.  */
                       if (d->changed & RM_INCLUDED)
-                        /* An included makefile.  We don't need
-                           to die, but we do want to complain.  */
-                        error (NILF,
-                               _("Included makefile '%s' was not found."),
-                               dep_name (d));
+                        /* An included makefile.  We don't need to die, but we
+                           do want to complain.  */
+                        error (NILF, l,
+                               _("Included makefile '%s' was not found."), dnm);
                       else
                         {
                           /* A normal makefile.  We must die later.  */
-                          error (NILF, _("Makefile '%s' was not found"),
-                                 dep_name (d));
+                          error (NILF, l,
+                                 _("Makefile '%s' was not found"), dnm);
                           any_failed = 1;
                         }
                     }

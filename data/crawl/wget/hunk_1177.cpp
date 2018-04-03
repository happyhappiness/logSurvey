                             {
                               logprintf (LOG_VERBOSE, _("\
 Already have correct symlink %s -> %s\n\n"),
-                                         con->target, escnonprint (f->linkto));
+                                         con->target, 
+                                         quotearg_style (escape_quoting_style, f->linkto));
                               dlthis = false;
                               break;
                             }
                         }
                     }
                   logprintf (LOG_VERBOSE, _("Creating symlink %s -> %s\n"),
-                             con->target, escnonprint (f->linkto));
+                             con->target, quotearg_style (escape_quoting_style, f->linkto));
                   /* Unlink before creating symlink!  */
                   unlink (con->target);
                   if (symlink (f->linkto, con->target) == -1)

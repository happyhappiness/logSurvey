         case FT_DIRECTORY:
           if (!opt.recursive)
             logprintf (LOG_NOTQUIET, _("Skipping directory %s.\n"),
-                       quote (escnonprint (f->name)));
+                       quote (f->name));
           break;
         case FT_PLAINFILE:
           /* Call the retrieve loop.  */

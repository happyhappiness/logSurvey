           break;
         case FT_UNKNOWN:
           logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
-                     escnonprint (f->name));
+                     quotearg_style (escape_quoting_style, f->name));
           break;
         }       /* switch */
 

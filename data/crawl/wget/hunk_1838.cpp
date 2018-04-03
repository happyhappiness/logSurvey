           break;
         case FT_UNKNOWN:
           logprintf (LOG_NOTQUIET, _("%s: unknown/unsupported file type.\n"),
-                     quotearg_style (escape_quoting_style, f->name));
+                     quote (f->name));
           break;
         }       /* switch */
 

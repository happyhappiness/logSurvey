             if (*p2 != '\0')
               /* There's no need to be ivory-tower about this: check for
                  one of the most common bugs found in makefiles...  */
-              fatal (fstart, _("missing separator%s"),
-                     (cmd_prefix == '\t' && !strneq (line, "        ", 8))
-                     ? "" : _(" (did you mean TAB instead of 8 spaces?)"));
+              if (cmd_prefix == '\t' && !strneq (line, "        ", 8))
+                fatal (fstart, _("missing separator (did you mean TAB instead of 8 spaces?)"));
+              else
+                fatal (fstart, _("missing separator"));
             continue;
           }
 

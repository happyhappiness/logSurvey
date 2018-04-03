               /* There's no need to be ivory-tower about this: check for
                  one of the most common bugs found in makefiles...  */
               fatal (fstart, _("missing separator%s"),
-                     !strneq(line, "        ", 8) ? ""
-                     : _(" (did you mean TAB instead of 8 spaces?)"));
+                     (cmd_prefix == '\t' && !strneq(line, "        ", 8))
+                     ? "" : _(" (did you mean TAB instead of 8 spaces?)"));
             continue;
           }
 

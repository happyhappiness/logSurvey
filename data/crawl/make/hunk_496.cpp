                       else
                         op = cs->long_name;
 
-                      error (NILF, _("the `%s%s' option requires a non-empty string argument"),
+                      error (NILF, _("the '%s%s' option requires a non-empty string argument"),
                              short_option (cs->c) ? "-" : "--", op);
                       bad = 1;
                     }

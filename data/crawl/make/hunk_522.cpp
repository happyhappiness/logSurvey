 #define warn_undefined(n,l) do{\
                               if (warn_undefined_variables_flag) \
                                 error (reading_file, \
-                                       _("warning: undefined variable `%.*s'"), \
+                                       _("warning: undefined variable '%.*s'"), \
                                 (int)(l), (n)); \
                               }while(0)
 

 #define define_variable_for_file(n,l,v,o,r,f) \
           define_variable_in_set((n),(l),(v),(o),(r),(f)->variables->set,NILF)
 
+/* Warn that NAME is an undefined variable.  */
+
+#define warn_undefined(n,l) do{\
+                              if (warn_undefined_variables_flag) \
+                                error (reading_file, \
+                                       _("warning: undefined variable `%.*s'"), \
+                                (int)(l), (n)); \
+                              }while(0)
+
 extern char **target_environment PARAMS ((struct file *file));
 
 extern int export_all_variables;

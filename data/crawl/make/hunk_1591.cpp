 extern struct variable_set_list *current_variable_set_list;
 
 
-extern char *variable_buffer_output ();
-extern char *initialize_variable_output ();
-extern char *save_variable_output ();
-extern void restore_variable_output ();
-
 extern void push_new_variable_scope (), pop_variable_scope ();
 
 extern int handle_function ();
 
-extern char *variable_expand (), *allocated_variable_expand ();
-extern char *variable_expand_for_file ();
+extern char *variable_expand (), *variable_expand_for_file ();
 extern char *allocated_variable_expand_for_file ();
+#define	allocated_variable_expand(line) \
+  allocated_variable_expand_for_file (line, (struct file *) 0)
 extern char *expand_argument ();
 
 extern void define_automatic_variables ();

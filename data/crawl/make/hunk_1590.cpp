 
 extern int handle_function ();
 
+extern char *variable_buffer_output ();
 extern char *variable_expand (), *variable_expand_for_file ();
 extern char *allocated_variable_expand_for_file ();
 #define	allocated_variable_expand(line) \

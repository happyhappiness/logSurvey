 
 extern char *variable_buffer;
 extern struct variable_set_list *current_variable_set_list;
+extern struct variable *default_goal_var;
 
 /* expand.c */
 char *variable_buffer_output (char *ptr, const char *string, unsigned int length);

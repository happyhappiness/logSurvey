 extern struct variable_set_list *current_variable_set_list;
 
 /* expand.c */
-char *variable_buffer_output (char *ptr, char *string, unsigned int length);
-char *variable_expand (char *line);
-char *variable_expand_for_file (char *line, struct file *file);
-char *allocated_variable_expand_for_file (char *line, struct file *file);
+char *variable_buffer_output (char *ptr, const char *string, unsigned int length);
+char *variable_expand (const char *line);
+char *variable_expand_for_file (const char *line, struct file *file);
+char *allocated_variable_expand_for_file (const char *line, struct file *file);
 #define	allocated_variable_expand(line) \
   allocated_variable_expand_for_file (line, (struct file *) 0)
 char *expand_argument (const char *str, const char *end);
-char *variable_expand_string (char *line, char *string, long length);
+char *variable_expand_string (char *line, const char *string, long length);
 void install_variable_buffer (char **bufp, unsigned int *lenp);
 void restore_variable_buffer (char *buf, unsigned int len);
 
 /* function.c */
-int handle_function (char **op, char **stringp);
-int pattern_matches (char *pattern, char *percent, char *str);
+int handle_function (char **op, const char **stringp);
+int pattern_matches (const char *pattern, const char *percent, const char *str);
 char *subst_expand (char *o, char *text, char *subst, char *replace,
                     unsigned int slen, unsigned int rlen, int by_word);
 char *patsubst_expand (char *o, char *text, char *pattern, char *replace,

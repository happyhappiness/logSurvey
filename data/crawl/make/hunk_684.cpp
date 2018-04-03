 extern struct variable_set_list *current_variable_set_list;
 
 /* expand.c */
-extern char *variable_buffer_output PARAMS ((char *ptr, char *string, unsigned int length));
-extern char *variable_expand PARAMS ((char *line));
-extern char *variable_expand_for_file PARAMS ((char *line, struct file *file));
-extern char *allocated_variable_expand_for_file PARAMS ((char *line, struct file *file));
+char *variable_buffer_output (char *ptr, char *string, unsigned int length);
+char *variable_expand (char *line);
+char *variable_expand_for_file (char *line, struct file *file);
+char *allocated_variable_expand_for_file (char *line, struct file *file);
 #define	allocated_variable_expand(line) \
   allocated_variable_expand_for_file (line, (struct file *) 0)
-extern char *expand_argument PARAMS ((const char *str, const char *end));
-extern char *variable_expand_string PARAMS ((char *line, char *string,
-                                             long length));
-extern void install_variable_buffer PARAMS ((char **bufp, unsigned int *lenp));
-extern void restore_variable_buffer PARAMS ((char *buf, unsigned int len));
+char *expand_argument (const char *str, const char *end);
+char *variable_expand_string (char *line, char *string, long length);
+void install_variable_buffer (char **bufp, unsigned int *lenp);
+void restore_variable_buffer (char *buf, unsigned int len);
 
 /* function.c */
-extern int handle_function PARAMS ((char **op, char **stringp));
-extern int pattern_matches PARAMS ((char *pattern, char *percent, char *str));
-extern char *subst_expand PARAMS ((char *o, char *text, char *subst, char *replace,
-		unsigned int slen, unsigned int rlen, int by_word));
-extern char *patsubst_expand PARAMS ((char *o, char *text, char *pattern, char *replace,
-		char *pattern_percent, char *replace_percent));
+int handle_function (char **op, char **stringp);
+int pattern_matches (char *pattern, char *percent, char *str);
+char *subst_expand (char *o, char *text, char *subst, char *replace,
+                    unsigned int slen, unsigned int rlen, int by_word);
+char *patsubst_expand (char *o, char *text, char *pattern, char *replace,
+                       char *pattern_percent, char *replace_percent);
 
 /* expand.c */
-extern char *recursively_expand_for_file PARAMS ((struct variable *v,
-                                                  struct file *file));
+char *recursively_expand_for_file (struct variable *v, struct file *file);
 #define recursively_expand(v)   recursively_expand_for_file (v, NULL)
 
 /* variable.c */
-extern struct variable_set_list *create_new_variable_set PARAMS ((void));
-extern void free_variable_set PARAMS ((struct variable_set_list *));
-extern struct variable_set_list *push_new_variable_scope PARAMS ((void));
-extern void pop_variable_scope PARAMS ((void));
-extern void define_automatic_variables PARAMS ((void));
-extern void initialize_file_variables PARAMS ((struct file *file, int read));
-extern void print_file_variables PARAMS ((struct file *file));
-extern void print_variable_set PARAMS ((struct variable_set *set, char *prefix));
-extern void merge_variable_set_lists PARAMS ((struct variable_set_list **to_list, struct variable_set_list *from_list));
-extern struct variable *do_variable_definition PARAMS ((const struct floc *flocp, const char *name, char *value, enum variable_origin origin, enum variable_flavor flavor, int target_var));
-extern struct variable *parse_variable_definition PARAMS ((struct variable *v, char *line));
-extern struct variable *try_variable_definition PARAMS ((const struct floc *flocp, char *line, enum variable_origin origin, int target_var));
-extern void init_hash_global_variable_set PARAMS ((void));
-extern void hash_init_function_table PARAMS ((void));
-extern struct variable *lookup_variable PARAMS ((const char *name, unsigned int length));
-extern struct variable *lookup_variable_in_set PARAMS ((const char *name,
-                                                        unsigned int length,
-                                                        const struct variable_set *set));
-
-extern struct variable *define_variable_in_set
-    PARAMS ((const char *name, unsigned int length, char *value,
-             enum variable_origin origin, int recursive,
-             struct variable_set *set, const struct floc *flocp));
+struct variable_set_list *create_new_variable_set (void);
+void free_variable_set (struct variable_set_list *);
+struct variable_set_list *push_new_variable_scope (void);
+void pop_variable_scope (void);
+void define_automatic_variables (void);
+void initialize_file_variables (struct file *file, int read);
+void print_file_variables (struct file *file);
+void print_variable_set (struct variable_set *set, char *prefix);
+void merge_variable_set_lists (struct variable_set_list **to_list,
+                               struct variable_set_list *from_list);
+struct variable *do_variable_definition (const struct floc *flocp,
+                                         const char *name, char *value,
+                                         enum variable_origin origin,
+                                         enum variable_flavor flavor,
+                                         int target_var);
+struct variable *parse_variable_definition (struct variable *v, char *line);
+struct variable *try_variable_definition (const struct floc *flocp, char *line,
+                                          enum variable_origin origin,
+                                          int target_var);
+void init_hash_global_variable_set (void);
+void hash_init_function_table (void);
+struct variable *lookup_variable (const char *name, unsigned int length);
+struct variable *lookup_variable_in_set (const char *name, unsigned int length,
+                                         const struct variable_set *set);
+
+struct variable *define_variable_in_set (const char *name, unsigned int length,
+                                         char *value,
+                                         enum variable_origin origin,
+                                         int recursive,
+                                         struct variable_set *set,
+                                         const struct floc *flocp);
 
 /* Define a variable in the current variable set.  */
 

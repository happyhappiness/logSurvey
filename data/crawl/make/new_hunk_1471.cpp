
extern struct variable_set_list *current_variable_set_list;

/* expand.c */
extern char *variable_buffer_output PARAMS ((char *ptr, char *string, unsigned int length));
extern char *variable_expand PARAMS ((char *line));
extern char *variable_expand_for_file PARAMS ((char *line, struct file *file));
extern char *allocated_variable_expand_for_file PARAMS ((char *line, struct file *file));
#define	allocated_variable_expand(line) \
  allocated_variable_expand_for_file (line, (struct file *) 0)
extern char *expand_argument PARAMS ((char *str, char *end));

/* function.c */
extern int handle_function PARAMS ((char **op, char **stringp));
extern int pattern_matches PARAMS ((char *pattern, char *percent, char *word));
extern char *subst_expand PARAMS ((char *o, char *text, char *subst, char *replace,
		unsigned int slen, unsigned int rlen, int by_word, int suffix_only));
extern char *patsubst_expand PARAMS ((char *o, char *text, char *pattern, char *replace,
		char *pattern_percent, char *replace_percent));

/* expand.c */
extern char *recursively_expand PARAMS ((struct variable *v));

/* variable.c */
extern void push_new_variable_scope PARAMS ((void));
extern void pop_variable_scope PARAMS ((void));
extern void define_automatic_variables PARAMS ((void));
extern void initialize_file_variables PARAMS ((struct file *file));
extern void print_file_variables PARAMS ((struct file *file));
extern void merge_variable_set_lists PARAMS ((struct variable_set_list **setlist0, struct variable_set_list *setlist1));
extern struct variable *try_variable_definition PARAMS ((char *filename, unsigned int lineno, char *line, enum variable_origin origin));

extern struct variable *lookup_variable PARAMS ((char *name, unsigned int length));
extern struct variable *define_variable PARAMS ((char *name, unsigned int length, char *value,
		enum variable_origin origin, int recursive));
extern struct variable *define_variable_for_file PARAMS ((char *name, unsigned int length,
		char *value, enum variable_origin origin, int recursive, struct file *file));
extern char **target_environment PARAMS ((struct file *file));

extern int export_all_variables;

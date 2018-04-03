
extern struct variable_set_list *current_variable_set_list;


extern void push_new_variable_scope (), pop_variable_scope ();

extern int handle_function ();

extern char *variable_buffer_output ();
extern char *variable_expand (), *variable_expand_for_file ();
extern char *allocated_variable_expand_for_file ();
#define	allocated_variable_expand(line) \
  allocated_variable_expand_for_file (line, (struct file *) 0)
extern char *expand_argument ();

extern void define_automatic_variables ();
extern void initialize_file_variables ();
extern void print_file_variables ();

extern void merge_variable_set_lists ();

extern struct variable *try_variable_definition ();

extern struct variable *lookup_variable (), *define_variable ();
extern struct variable *define_variable_for_file ();

extern int pattern_matches ();
extern char *subst_expand (), *patsubst_expand (), *recursively_expand ();

extern char **target_environment ();
extern int export_all_variables;

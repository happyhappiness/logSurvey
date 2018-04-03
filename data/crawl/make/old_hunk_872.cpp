#define define_variable_for_file(n,l,v,o,r,f) \
          define_variable_in_set((n),(l),(v),(o),(r),(f)->variables->set,NILF)

extern char **target_environment PARAMS ((struct file *file));

extern int export_all_variables;

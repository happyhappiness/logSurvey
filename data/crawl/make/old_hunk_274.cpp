/* Warn that NAME is an undefined variable.  */

#define warn_undefined(n,l) do{\
                              if (warn_undefined_variables_flag) \
                                error (reading_file, \
                                       _("warning: undefined variable '%.*s'"), \
                                (int)(l), (n)); \
                              }while(0)

char **target_environment (struct file *file);

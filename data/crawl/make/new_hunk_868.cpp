static char *allocated_variable_append PARAMS ((const struct variable *v));

char *
recursively_expand_for_file (v, file)
     struct variable *v;
     struct file *file;
{
  char *value;
  struct variable_set_list *save;

  if (v->expanding)
    {
      if (!v->exp_count)
        /* Expanding V causes infinite recursion.  Lose.  */
        fatal (reading_file,
               _("Recursive variable `%s' references itself (eventually)"),
               v->name);
      --v->exp_count;
    }

  if (file)
    {
      save = current_variable_set_list;
      current_variable_set_list = file->variables;
    }

  v->expanding = 1;
  if (v->append)

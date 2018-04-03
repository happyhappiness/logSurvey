recursively_expand_for_file (struct variable *v, struct file *file)
{
  char *value;
  struct variable_set_list *save = 0;
  int set_reading = 0;

  if (v->expanding)
    {
      if (!v->exp_count)
        /* Expanding V causes infinite recursion.  Lose.  */
        fatal (reading_file,
               _("Recursive variable `%s' references itself (eventually)"),
               v->name);
      --v->exp_count;

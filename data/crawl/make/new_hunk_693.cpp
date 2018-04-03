recursively_expand_for_file (struct variable *v, struct file *file)
{
  char *value;
  const struct floc *this_var;
  const struct floc **saved_varp;
  struct variable_set_list *save;
  int set_reading = 0;

  /* Don't install a new location if this location is empty.
     This can happen for command-line variables, builtin variables, etc.  */
  saved_varp = expanding_var;
  if (v->fileinfo.filenm)
    {
      this_var = &v->fileinfo;
      expanding_var = &this_var;
    }

  if (v->expanding)
    {
      if (!v->exp_count)
        /* Expanding V causes infinite recursion.  Lose.  */
        fatal (this_var,
               _("Recursive variable `%s' references itself (eventually)"),
               v->name);
      --v->exp_count;

static char *allocated_variable_append PARAMS ((const struct variable *v));

char *
recursively_expand (v)
     register struct variable *v;
{
  char *value;

  if (v->expanding)
    /* Expanding V causes infinite recursion.  Lose.  */
    fatal (reading_file,
           _("Recursive variable `%s' references itself (eventually)"),
           v->name);

  v->expanding = 1;
  if (v->append)

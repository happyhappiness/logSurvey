  if (buf > variable_buffer)
    buf = variable_buffer_output (buf, " ", 1);

  return variable_buffer_output (buf, v->value, strlen (v->value));
}


static char *
allocated_variable_append (const struct variable *v)
{
  char *val, *retval;

  /* Construct the appended variable value.  */


func_firstword (char *o, char **argv, const char *funcname UNUSED)
{
  unsigned int i;
  char *words = argv[0];    /* Use a temp variable for find_next_token */
  char *p = find_next_token (&words, &i);

  if (p != 0)
    o = variable_buffer_output (o, p, i);

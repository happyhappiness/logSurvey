   Write the results to LINE, which must point into `variable_buffer'.  If
   LINE is NULL, start at the beginning of the buffer.
   Return a pointer to LINE, or to the beginning of the buffer if LINE is
   NULL.
 */
char *
variable_expand_string (char *line, const char *string, long length)
{
  struct variable *v;
  const char *p, *p1;
  char *abuf = NULL;
  char *o;
  unsigned int line_offset;

  if (!line)
    line = initialize_variable_output();
  o = line;
  line_offset = line - variable_buffer;

  if (length == 0)
    {
      variable_buffer_output (o, "", 1);
      return (variable_buffer);
    }

  /* If we want a subset of the string, allocate a temporary buffer for it.
     Most of the functions we use here don't work with length limits.  */
  if (length > 0 && string[length] != '\0')
    {
      abuf = xmalloc(length+1);
      memcpy(abuf, string, length);
      abuf[length] = '\0';
      string = abuf;
    }
  p = string;

  while (1)
    {
      /* Copy all following uninteresting chars all at once to the

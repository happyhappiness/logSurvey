   Write the results to LINE, which must point into `variable_buffer'.  If
   LINE is NULL, start at the beginning of the buffer.
   Return a pointer to LINE, or to the beginning of the buffer if LINE is
   NULL.  */

char *
variable_expand_string (char *line, char *string, long length)
{
  struct variable *v;
  char *p, *o, *p1;
  char save_char = '\0';
  unsigned int line_offset;

  if (!line)
    line = initialize_variable_output();

  p = string;
  o = line;
  line_offset = line - variable_buffer;

  if (length >= 0)
    {
      save_char = string[length];
      string[length] = '\0';
    }

  while (1)
    {
      /* Copy all following uninteresting chars all at once to the

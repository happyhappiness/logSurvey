   the variable to be defined.  The following lines remain to be read.  */

static struct variable *
do_define (char *name, enum variable_origin origin, struct ebuffer *ebuf)
{
  struct variable *v;
  enum variable_flavor flavor;
  struct floc defstart;
  int nlevels = 1;
  unsigned int length = 100;
  char *definition = xmalloc (length);
  unsigned int idx = 0;
  char *p, *var;

  defstart = ebuf->floc;

  p = parse_variable_definition (name, &flavor);
  if (p == NULL)
    /* No assignment token, so assume recursive.  */
    flavor = f_recursive;
  else
    {
      if (*(next_token (p)) != '\0')
        error (&defstart, _("extraneous text after `define' directive"));

      /* Chop the string before the assignment token to get the name.  */
      p[flavor == f_recursive ? -1 : -2] = '\0';
    }

  /* Expand the variable name and find the beginning (NAME) and end.  */
  var = allocated_variable_expand (name);
  name = next_token (var);
  if (*name == '\0')
    fatal (&defstart, _("empty variable name"));
  p = name + strlen (name) - 1;
  while (p > name && isblank ((unsigned char)*p))
    --p;
  p[1] = '\0';

  /* Now read the value of the variable.  */
  while (1)
    {
      unsigned int len;
      char *line;
      long nlines = readline (ebuf);

      /* If there is nothing left to be eval'd, there's no 'endef'!!  */
      if (nlines < 0)
        fatal (&defstart, _("missing `endef', unterminated `define'"));

      ebuf->floc.lineno += nlines;
      line = ebuf->buffer;

      collapse_continuations (line);

      /* If the line doesn't begin with a tab, test to see if it introduces
         another define, or ends one.  Stop if we find an 'endef' */
      if (line[0] != cmd_prefix)
        {
          p = next_token (line);

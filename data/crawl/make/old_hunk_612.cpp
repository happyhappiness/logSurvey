   the variable to be defined.  The following lines remain to be read.  */

static struct variable *
do_define (char *name, unsigned int namelen,
           enum variable_origin origin, struct ebuffer *ebuf)
{
  struct floc defstart;
  long nlines = 0;
  int nlevels = 1;
  unsigned int length = 100;
  char *definition = xmalloc (length);
  unsigned int idx = 0;
  char *p;

  /* Expand the variable name.  */
  char *var = alloca (namelen + 1);
  memcpy (var, name, namelen);
  var[namelen] = '\0';
  var = variable_expand (var);

  defstart = ebuf->floc;

  while (1)
    {
      unsigned int len;
      char *line;

      nlines = readline (ebuf);
      ebuf->floc.lineno += nlines;

      /* If there is nothing left to eval, we're done. */
      if (nlines < 0)
        break;

      line = ebuf->buffer;

      collapse_continuations (line);

      /* If the line doesn't begin with a tab, test to see if it introduces
         another define, or ends one.  */

      /* Stop if we find an 'endef' */
      if (line[0] != cmd_prefix)
        {
          p = next_token (line);

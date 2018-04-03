#endif /* !VMS */
  return 0;
}

/* Parse a string into a sequence of filenames represented as a chain of
   struct nameseq's and return that chain.  Optionally expand the strings via
   glob().

   The string is passed as STRINGP, the address of a string pointer.
   The string pointer is updated to point at the first character
   not parsed, which either is a null char or equals STOPCHAR.

   SIZE is how big to construct chain elements.
   This is useful if we want them actually to be other structures
   that have room for additional info.

   PREFIX, if non-null, is added to the beginning of each filename.

   FLAGS allows one or more of the following bitflags to be set:
        PARSEFS_NOSTRIP - Do no strip './'s off the beginning
        PARSEFS_NOGLOB  - Do not expand globbing characters
        PARSEFS_EXISTS  - Only return globbed files that actually exist
                          (cannot also set NOGLOB)
        PARSEFS_NOCACHE - Do not add filenames to the strcache (caller frees)
  */

struct nameseq *
parse_file_seq (char **stringp, unsigned int size, int stopchar,
                const char *prefix, int flags)
{
  extern void dir_setup_glob (glob_t *glob);

  /* tmp points to tmpbuf after the prefix, if any.
     tp is the end of the buffer. */
  static char *tmpbuf = NULL;
  static int tmpbuf_len = 0;

  int cachep = (! (flags & PARSEFS_NOCACHE));

  struct nameseq *new = 0;
  struct nameseq **newp = &new;
#define NEWELT(_n)  do { \
                        const char *__n = (_n); \
                        *newp = xcalloc (size); \
                        (*newp)->name = (cachep ? strcache_add (__n) : xstrdup (__n)); \
                        newp = &(*newp)->next; \
                    } while(0)

  char *p;
  glob_t gl;
  char *tp;

#ifdef VMS
# define VMS_COMMA ','
#else
# define VMS_COMMA 0
#endif

  if (size < sizeof (struct nameseq))
    size = sizeof (struct nameseq);

  if (! (flags & PARSEFS_NOGLOB))
    dir_setup_glob (&gl);

  /* Get enough temporary space to construct the largest possible target.  */
  {
    int l = strlen (*stringp) + 1;
    if (l > tmpbuf_len)
      {
        tmpbuf = xrealloc (tmpbuf, l);
        tmpbuf_len = l;
      }
  }
  tp = tmpbuf;

  /* Parse STRING.  P will always point to the end of the parsed content.  */
  p = *stringp;
  while (1)
    {
      const char *name;
      const char **nlist = 0;
      char *tildep = 0;
#ifndef NO_ARCHIVES
      char *arname = 0;
      char *memname = 0;
#endif
      char *s;
      int nlen;
      int i;

      /* Skip whitespace; at the end of the string or STOPCHAR we're done.  */
      p = next_token (p);
      if (*p == '\0' || *p == stopchar)
	break;

      /* There are names left, so find the end of the next name.
         Throughout this iteration S points to the start.  */
      s = p;
      p = find_char_unquote (p, stopchar, VMS_COMMA, 1, 0);
#ifdef VMS
	/* convert comma separated list to space separated */
      if (p && *p == ',')
	*p =' ';
#endif
#ifdef _AMIGA
      if (stopchar == ':' && p && *p == ':'
          && !(isspace ((unsigned char)p[1]) || !p[1]
               || isspace ((unsigned char)p[-1])))
	p = find_char_unquote (p+1, stopchar, VMS_COMMA, 1, 0);
#endif
#ifdef HAVE_DOS_PATHS
    /* For DOS paths, skip a "C:\..." or a "C:/..." until we find the
       first colon which isn't followed by a slash or a backslash.
       Note that tokens separated by spaces should be treated as separate
       tokens since make doesn't allow path names with spaces */
    if (stopchar == ':')
      while (p != 0 && !isspace ((unsigned char)*p) &&
             (p[1] == '\\' || p[1] == '/') && isalpha ((unsigned char)p[-1]))
        p = find_char_unquote (p + 1, stopchar, VMS_COMMA, 1, 0);
#endif
      if (p == 0)
	p = s + strlen (s);

      /* Strip leading "this directory" references.  */
      if (! (flags & PARSEFS_NOSTRIP))
#ifdef VMS
	/* Skip leading `[]'s.  */
	while (p - s > 2 && s[0] == '[' && s[1] == ']')
#else
	/* Skip leading `./'s.  */
	while (p - s > 2 && s[0] == '.' && s[1] == '/')
#endif
	  {
            /* Skip "./" and all following slashes.  */
	    s += 2;
	    while (*s == '/')
	      ++s;
	  }

      /* Extract the filename just found, and skip it.
         Set NAME to the string, and NLEN to its length.  */

      if (s == p)
        {
	/* The name was stripped to empty ("./"). */
#if defined(VMS)
          continue;
#elif defined(_AMIGA)
          /* PDS-- This cannot be right!! */
          tp[0] = '\0';
          nlen = 0;
#else
          tp[0] = '.';
          tp[1] = '/';
          tp[2] = '\0';
          nlen = 2;
#endif
        }
      else
	{
#ifdef VMS
/* VMS filenames can have a ':' in them but they have to be '\'ed but we need
 *  to remove this '\' before we can use the filename.
 * xstrdup called because S may be read-only string constant.
 */
	  char *n = tp;
	  while (s < p)
	    {
	      if (s[0] == '\\' && s[1] == ':')
                ++s;
	      *(n++) = *(s++);
	    }
          n[0] = '\0';
          nlen = strlen (tp);
#else
          nlen = p - s;
          memcpy (tp, s, nlen);
          tp[nlen] = '\0';
#endif
        }

      /* At this point, TP points to the element and NLEN is its length.  */

#ifndef NO_ARCHIVES
      /* If this is the start of an archive group that isn't complete, set up
         to add the archive prefix for future files.

         TP == TMP means we're not already in an archive group.  Ignore
         something starting with `(', as that cannot actually be an
         archive-member reference (and treating it as such results in an empty
         file name, which causes much lossage).  Also if it ends in ")" then
         it's a complete reference so we don't need to treat it specially.  */

      if (tp == tmpbuf && tp[0] != '(' && tp[nlen-1] != ')')
        {
          char *n = strchr (tp, '(');
          if (n)
            {
              /* This is the first element in an open archive group.  It looks
                 like "lib(mem".  Remember the close paren.  */
              nlen -= (n + 1) - tp;
              tp = n + 1;

              /* If we have just "lib(", part of something like "lib( a b)",
                 go to the next item.  */
              if (! nlen)
                continue;
            }
        }

      /* If we are inside an archive group, make sure it has an end.  */
      if (tp > tmpbuf)
        {
          if (tp[nlen-1] == ')')
            {
              /* This is the natural end; reset TP.  */
              tp = tmpbuf;

              /* This is just ")", something like "lib(a b )": skip it.  */
              if (nlen == 1)
                continue;
            }
          else
            {
              /* Not the end, so add a "fake" end.  */
              tp[nlen++] = ')';
              tp[nlen] = '\0';
            }
        }
#endif

      /* If we're not globbing we're done: add it to the end of the chain.
         Go to the next item in the string.  */
      if (flags & PARSEFS_NOGLOB)
        {
          NEWELT (concat (2, prefix, tp));
          continue;
        }

      /* If we get here we know we're doing glob expansion.
         TP is a string in tmpbuf.  NLEN is no longer used.
         We may need to do more work: after this NAME will be set.  */
      name = tp;

      /* Expand tilde if applicable.  */
      if (tp[0] == '~')
	{
	  tildep = tilde_expand (tp);
	  if (tildep != 0)
            name = tildep;
	}

#ifndef NO_ARCHIVES
      /* If NAME is an archive member reference replace it with the archive
         file name, and save the member name in MEMNAME.  We will glob on the
         archive name and then reattach MEMNAME later.  */
      if (ar_name (name))
	{
	  ar_parse_name (name, &arname, &memname);
	  name = arname;
	}
#endif /* !NO_ARCHIVES */

      switch (glob (name, GLOB_NOSORT|GLOB_ALTDIRFUNC, NULL, &gl))
	{
	case GLOB_NOSPACE:
	  fatal (NILF, _("virtual memory exhausted"));

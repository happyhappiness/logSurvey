#endif /* !VMS */
  return 0;
}

/* Given a chain of struct nameseq's describing a sequence of filenames,
   in reverse of the intended order, return a new chain describing the
   result of globbing the filenames.  The new chain is in forward order.
   The links of the old chain are freed or used in the new chain.
   Likewise for the names in the old chain.

   SIZE is how big to construct chain elements.
   This is useful if we want them actually to be other structures
   that have room for additional info.

   If EXISTS_ONLY is true only return existing files.  */

struct nameseq *
multi_glob (struct nameseq *chain, unsigned int size, int exists_only)
{
  void dir_setup_glob (glob_t *);
  struct nameseq *new = 0;
  struct nameseq *old;
  struct nameseq *nexto;
  glob_t gl;

  dir_setup_glob (&gl);

  for (old = chain; old != 0; old = nexto)
    {
      int r;
      const char **nlist = 0;
      int i = 0;
      const char *gname;
#ifndef NO_ARCHIVES
      char *arname = 0;
      char *memname = 0;
#endif
      nexto = old->next;
      gname = old->name;

      if (gname[0] == '~')
	{
	  char *newname = tilde_expand (old->name);
	  if (newname != 0)
            gname = newname;
	}

#ifndef NO_ARCHIVES
      if (ar_name (gname))
	{
	  /* OLD->name is an archive member reference.  Replace it with the
	     archive file name, and save the member name in MEMNAME.  We will
	     glob on the archive name and then reattach MEMNAME later.  */
	  ar_parse_name (gname, &arname, &memname);
	  gname = arname;
	}
#endif /* !NO_ARCHIVES */

      r = glob (gname, GLOB_NOSORT|GLOB_ALTDIRFUNC, NULL, &gl);
      switch (r)
	{
	case GLOB_NOSPACE:
	  fatal (NILF, _("virtual memory exhausted"));

    {
      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
      if (! global_dl)
        fatal (flocp, _("Failed to open global symbol table: %s"), dlerror ());
    }

  symp = (load_func_t) dlsym (global_dl, symname);
  if (! symp)
    {
      struct load_list *new;
      void *dlp = NULL;

    /* If the path has no "/", try the current directory first.  */
      if (! strchr (ldname, '/')
#ifdef HAVE_DOS_PATHS
          && ! strchr (ldname, '\\')
#endif
         )
        dlp = dlopen (concat (2, "./", ldname), RTLD_LAZY|RTLD_GLOBAL);

      /* If we haven't opened it yet, try the default search path.  */
      if (! dlp)
        dlp = dlopen (ldname, RTLD_LAZY|RTLD_GLOBAL);

      /* Still no?  Then fail.  */
      if (! dlp)
        {
          if (noerror)
            DB (DB_BASIC, ("%s", dlerror ()));
          else
            error (flocp, "%s", dlerror ());
          return NULL;
        }

      /* Assert that the GPL license symbol is defined.  */
      symp = dlsym (dlp, "plugin_is_GPL_compatible");
      if (! symp)
        fatal (flocp, _("Loaded object %s is not declared to be GPL compatible"),
               ldname);

      symp = dlsym (dlp, symname);
      if (! symp)
        fatal (flocp, _("Failed to load symbol %s from %s: %s"),
               symname, ldname, dlerror ());

      /* Add this symbol to a trivial lookup table.  This is not efficient but
         it's highly unlikely we'll be loading lots of objects, and we only
         need it to look them up on unload, if we rebuild them.  */
      new = xmalloc (sizeof (struct load_list));
      new->name = xstrdup (ldname);
      new->dlp = dlp;
      new->next = loaded_syms;
      loaded_syms = new;
    }

  return symp;
}

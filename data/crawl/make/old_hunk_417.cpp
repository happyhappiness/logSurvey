
  DB (DB_VERBOSE, (_("Loading symbol %s from %s\n"), symname, *ldname));

  /* See if it's already defined.  */
  symp = (load_func_t) dlsym (global_dl, symname);
  if (! symp) {
    void *dlp = NULL;

    /* If the path has no "/", try the current directory first.  */
    if (! strchr (*ldname, '/'))
      dlp = dlopen (concat (2, "./", *ldname), RTLD_LAZY|RTLD_GLOBAL);

    /* If we haven't opened it yet, try the default search path.  */
    if (! dlp)
      dlp = dlopen (*ldname, RTLD_LAZY|RTLD_GLOBAL);

    /* Still no?  Then fail.  */
    if (! dlp)
      {
        if (noerror)
          DB (DB_BASIC, ("%s", dlerror()));
        else
          error (flocp, "%s", dlerror());
        return 0;
      }

    symp = dlsym (dlp, symname);
    if (! symp)
      fatal (flocp, _("Failed to load symbol %s from %s: %s"),
             symname, *ldname, dlerror());
  }

  /* Invoke the symbol to initialize the loaded object.  */
  return init_symbol(flocp, *ldname, symp);
}

#else

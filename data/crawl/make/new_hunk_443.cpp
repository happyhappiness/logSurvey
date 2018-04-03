    symp = dlsym (dlp, symname);
    if (! symp)
      fatal (flocp, _("Failed to load symbol %s from %s: %s"),
             symname, *ldname, dlerror());
  }

  /* Invoke the symbol to initialize the loaded object.  */
  return init_symbol(flocp, *ldname, symp);
}

#else

int
load_file (const struct floc *flocp, const char **ldname, int noerror)
{
  if (! noerror)
    fatal (flocp, _("The 'load' operation is not supported on this platform."));

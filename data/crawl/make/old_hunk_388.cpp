      }

    /* Assert that the GPL license symbol is defined.  */
    symp = dlsym (*dlp, "plugin_is_GPL_compatible");
    if (! symp)
      fatal (flocp, _("Loaded object %s is not declared to be GPL compatible"),
             ldname);

    symp = dlsym (*dlp, symname);
    if (! symp)
      fatal (flocp, _("Failed to load symbol %s from %s: %s"),
             symname, ldname, dlerror());
  }

  return symp;
}

int
load_file (const gmk_floc *flocp, const char **ldname, int noerror, void **dlp)
{
  int nmlen = strlen (*ldname);
  char *new = alloca (nmlen + CSTRLEN (SYMBOL_EXTENSION) + 1);

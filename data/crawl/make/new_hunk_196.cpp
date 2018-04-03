    {
      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
      if (! global_dl)
        {
          const char *err = dlerror ();
          OS (fatal, flocp, _("Failed to open global symbol table: %s"), err);
        }
    }

  symp = (load_func_t) dlsym (global_dl, symname);

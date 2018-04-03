    {
      global_dl = dlopen (NULL, RTLD_NOW|RTLD_GLOBAL);
      if (! global_dl)
        fatal (flocp, _("Failed to open global symbol table: %s"), dlerror ());
    }

  symp = (load_func_t) dlsym (global_dl, symname);

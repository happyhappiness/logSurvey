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
      symp = (load_func_t) dlsym (dlp, "plugin_is_GPL_compatible");
      if (! symp)
        fatal (flocp, _("Loaded object %s is not declared to be GPL compatible"),
               ldname);

      symp = (load_func_t) dlsym (dlp, symname);
      if (! symp)
        fatal (flocp, _("Failed to load symbol %s from %s: %s"),
               symname, ldname, dlerror ());

      /* Add this symbol to a trivial lookup table.  This is not efficient but
         it's highly unlikely we'll be loading lots of objects, and we only

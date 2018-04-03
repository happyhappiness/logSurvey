           _("Insufficient number of arguments (%d) to function `%s'"),
           argc, entry_p->name);

  if (!entry_p->func_ptr)
    fatal (reading_file, _("Unimplemented on this platform: function `%s'"),
           entry_p->name);

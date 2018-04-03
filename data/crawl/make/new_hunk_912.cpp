           _("Insufficient number of arguments (%d) to function `%s'"),
           argc, entry_p->name);

  /* I suppose technically some function could do something with no
     arguments, but so far none do, so just test it for all functions here
     rather than in each one.  We can change it later if necessary.  */

  if (!argc)
    return o;

  if (!entry_p->func_ptr)
    fatal (reading_file, _("Unimplemented on this platform: function `%s'"),
           entry_p->name);

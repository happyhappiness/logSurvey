  char *p;

  if (argc < (int)entry_p->minimum_args)
    fatal (*expanding_var,
           _("insufficient number of arguments (%d) to function '%s'"),
           argc, entry_p->name);


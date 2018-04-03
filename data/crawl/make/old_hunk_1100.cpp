
  if (argc < min)
    fatal (reading_file,
           "Insufficient number of arguments (%d) to function `%s'",
           argc, entry_p->name);

  if (!entry_p->func_ptr)
    fatal (reading_file, "Unimplemented on this platform: function `%s'",
           entry_p->name);

  return entry_p->func_ptr (o, argv, entry_p->name);

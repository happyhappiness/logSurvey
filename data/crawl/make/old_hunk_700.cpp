                         const struct function_table_entry *entry_p)
{
  if (argc < (int)entry_p->minimum_args)
    fatal (reading_file,
           _("Insufficient number of arguments (%d) to function `%s'"),
           argc, entry_p->name);

  /* I suppose technically some function could do something with no

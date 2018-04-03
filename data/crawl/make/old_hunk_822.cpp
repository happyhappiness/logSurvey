/* These must come after the definition of function_table.  */

static char *
expand_builtin_function (o, argc, argv, entry_p)
     char *o;
     int argc;
     char **argv;
     struct function_table_entry *entry_p;
{
  if (argc < (int)entry_p->minimum_args)
    fatal (reading_file,

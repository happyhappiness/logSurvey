expand_builtin_function (char *o, int argc, char **argv,
                         const struct function_table_entry *entry_p)
{
  if (argc < (int)entry_p->minimum_args)
    fatal (*expanding_var,
           _("insufficient number of arguments (%d) to function '%s'"),
           argc, entry_p->name);

  /* I suppose technically some function could do something with no
     arguments, but so far none do, so just test it for all functions here
     rather than in each one.  We can change it later if necessary.  */

  if (!argc)
    return o;

  if (!entry_p->func_ptr)
    fatal (*expanding_var,
           _("unimplemented on this platform: function '%s'"), entry_p->name);

  return entry_p->func_ptr (o, argv, entry_p->name);
}

/* Check for a function invocation in *STRINGP.  *STRINGP points at the

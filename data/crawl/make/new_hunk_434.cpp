expand_builtin_function (char *o, int argc, char **argv,
                         const struct function_table_entry *entry_p)
{
  char *p;

  if (argc < (int)entry_p->minimum_args)
    fatal (*expanding_var,
           _("insufficient number of arguments (%d) to function '%s'"),
           argc, entry_p->name);

  /* I suppose technically some function could do something with no arguments,
     but so far no internal ones do, so just test it for all functions here
     rather than in each one.  We can change it later if necessary.  */

  if (!argc && !entry_p->alloc_fn)
    return o;

  if (!entry_p->fptr.func_ptr)
    fatal (*expanding_var,
           _("unimplemented on this platform: function '%s'"), entry_p->name);

  if (!entry_p->alloc_fn)
    return entry_p->fptr.func_ptr (o, argv, entry_p->name);

  /* This function allocates memory and returns it to us.
     Write it to the variable buffer, then free it.  */

  p = entry_p->fptr.alloc_func_ptr (entry_p->name, argc, argv);
  if (p)
    {
      o = variable_buffer_output (o, p, strlen (p));
      free (p);
    }

  return o;
}

/* Check for a function invocation in *STRINGP.  *STRINGP points at the

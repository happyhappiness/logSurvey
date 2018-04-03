    return o;

  if (!entry_p->fptr.func_ptr)
    OS (fatal, *expanding_var,
        _("unimplemented on this platform: function '%s'"), entry_p->name);

  if (!entry_p->alloc_fn)
    return entry_p->fptr.func_ptr (o, argv, entry_p->name);

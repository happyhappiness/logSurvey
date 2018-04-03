  v->name = allocated_variable_expand (name);

  if (v->name[0] == '\0')
    O (fatal, &v->fileinfo, _("empty variable name"));

  return v;
}

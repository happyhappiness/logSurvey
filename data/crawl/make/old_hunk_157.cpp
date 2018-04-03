  merge_variable_set_lists (&to_file->variables, from_file->variables);

  if (to_file->double_colon && from_file->is_target && !from_file->double_colon)
    fatal (NILF, _("can't rename single-colon '%s' to double-colon '%s'"),
           from_file->name, to_hname);
  if (!to_file->double_colon  && from_file->double_colon)
    {
      if (to_file->is_target)
        fatal (NILF, _("can't rename double-colon '%s' to single-colon '%s'"),
               from_file->name, to_hname);
      else
        to_file->double_colon = from_file->double_colon;
    }

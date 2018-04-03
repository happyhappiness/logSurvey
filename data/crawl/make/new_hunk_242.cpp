#undef word1eq

  if (conditionals->if_cmds)
    O (fatal, fstart, _("missing 'endif'"));

  /* At eof, record the last rule.  */
  record_waiting_files ();

    }

  if (conditionals->if_cmds)
    fatal (&fileinfo, "missing `endif'");

  /* At eof, record the last rule.  */
  record_waiting_files ();

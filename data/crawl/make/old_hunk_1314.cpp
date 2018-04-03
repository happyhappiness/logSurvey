    }

  if (conditionals->if_cmds)
    makefile_fatal (filename, lineno, "missing `endif'");

  /* At eof, record the last rule.  */
  record_waiting_files ();

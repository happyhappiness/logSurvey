       command line (e.g. Cygnus GNUWIN32 sh.exe on WIN32 systems).  In these
       cases, run commands via a script file.  */
    if ((no_default_sh_exe || batch_mode_shell) && batch_filename_ptr) {
      FILE* batch = NULL;
      int id = GetCurrentProcessId();
      PATH_VAR(fbuf);

      /* create a file name */
      sprintf(fbuf, "make%d", id);
      *batch_filename_ptr = create_batch_filename (fbuf, unixy_shell);

      DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
                    *batch_filename_ptr));

      /* create batch file to execute command */
      batch = fopen (*batch_filename_ptr, "w");
      if (!unixy_shell)
        fputs ("@echo off\n", batch);
      fputs (command_ptr, batch);

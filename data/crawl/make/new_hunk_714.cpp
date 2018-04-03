       command line (e.g. Cygnus GNUWIN32 sh.exe on WIN32 systems).  In these
       cases, run commands via a script file.  */
    if ((no_default_sh_exe || batch_mode_shell) && batch_filename_ptr) {
      int temp_fd;
      FILE* batch = NULL;
      int id = GetCurrentProcessId();
      PATH_VAR(fbuf);

      /* create a file name */
      sprintf(fbuf, "make%d", id);
      *batch_filename_ptr = create_batch_file (fbuf, unixy_shell, &temp_fd);

      DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
                    *batch_filename_ptr));

      /* Create a FILE object for the batch file, and write to it the
	 commands to be executed.  */
      batch = _fdopen (temp_fd, "w");
      if (!unixy_shell)
        fputs ("@echo off\n", batch);
      fputs (command_ptr, batch);

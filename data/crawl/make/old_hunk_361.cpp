    /* Some shells do not work well when invoked as 'sh -c xxx' to run a
       command line (e.g. Cygnus GNUWIN32 sh.exe on WIN32 systems).  In these
       cases, run commands via a script file.  */
    if (just_print_flag && !(flags & COMMANDS_RECURSE)) {
      /* Need to allocate new_argv, although it's unused, because
        start_job_command will want to free it and its 0'th element.  */
      new_argv = xmalloc(2 * sizeof (char *));
      new_argv[0] = xstrdup ("");
      new_argv[1] = NULL;
    } else if ((no_default_sh_exe || batch_mode_shell) && batch_filename) {
      int temp_fd;
      FILE* batch = NULL;
      int id = GetCurrentProcessId();
      PATH_VAR(fbuf);

      /* create a file name */
      sprintf(fbuf, "make%d", id);
      *batch_filename = create_batch_file (fbuf, unixy_shell, &temp_fd);

      DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
                    *batch_filename));

      /* Create a FILE object for the batch file, and write to it the
	 commands to be executed.  Put the batch file in TEXT mode.  */
      _setmode (temp_fd, _O_TEXT);
      batch = _fdopen (temp_fd, "wt");
      if (!unixy_shell)
        fputs ("@echo off\n", batch);
      fputs (command_ptr, batch);
      fputc ('\n', batch);
      fclose (batch);
      DB (DB_JOBS, (_("Batch file contents:%s\n\t%s\n"),
		    !unixy_shell ? "\n\t@echo off" : "", command_ptr));

      /* create argv */
      new_argv = xmalloc(3 * sizeof (char *));
      if (unixy_shell) {
        new_argv[0] = xstrdup (shell);
        new_argv[1] = *batch_filename; /* only argv[0] gets freed later */
      } else {
        new_argv[0] = xstrdup (*batch_filename);
        new_argv[1] = NULL;
      }
      new_argv[2] = NULL;
    } else
#endif /* WINDOWS32 */

    if (unixy_shell)

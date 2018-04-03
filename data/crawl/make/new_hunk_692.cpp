                    *batch_filename_ptr));

      /* Create a FILE object for the batch file, and write to it the
	 commands to be executed.  Put the batch file in TEXT mode.  */
      _setmode (temp_fd, _O_TEXT);
      batch = _fdopen (temp_fd, "wt");
      if (!unixy_shell)
        fputs ("@echo off\n", batch);
      fputs (command_ptr, batch);

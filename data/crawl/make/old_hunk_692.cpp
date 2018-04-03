                    *batch_filename_ptr));

      /* Create a FILE object for the batch file, and write to it the
	 commands to be executed.  */
      batch = _fdopen (temp_fd, "w");
      if (!unixy_shell)
        fputs ("@echo off\n", batch);
      fputs (command_ptr, batch);

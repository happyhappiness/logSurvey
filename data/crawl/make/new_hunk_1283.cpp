
      /* create batch file to execute command */
      batch = fopen (*batch_filename_ptr, "w");
      if (!unixy_shell)
        fputs ("@echo off\n", batch);
      fputs (command_ptr, batch);
      fputc ('\n', batch);
      fclose (batch);

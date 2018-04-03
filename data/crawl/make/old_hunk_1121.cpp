      }

      if (debug_flag)
        printf("Creating temporary batch file %s\n", *batch_filename_ptr);

      /* create batch file to execute command */
      batch = fopen (*batch_filename_ptr, "w");

        strcat(*batch_filename_ptr, ".sh");
      }

      DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
                    *batch_filename_ptr));

      /* create batch file to execute command */
      batch = fopen (*batch_filename_ptr, "w");

	    while (shell_function_completed == 0)
	      reap_children (1, 0);

            if (batch_filename) {
              if (debug_flag)
                printf("Cleaning up temporary batch file %s\n", batch_filename);
              remove(batch_filename);
              free(batch_filename);
            }
	    shell_function_pid = 0;

	    /* The child_handler function will set shell_function_completed

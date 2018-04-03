	    while (shell_function_completed == 0)
	      reap_children (1, 0);

	    shell_function_pid = 0;

	    /* The child_handler function will set shell_function_completed

	    --argc;
	  }

	execvp (shell, new_argv);
	if (errno == ENOENT)
	  error (NILF, _("%s: Shell program not found"), shell);
	else

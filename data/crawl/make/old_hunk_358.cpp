# endif

        new_argv[i] = argv[0];
	while (argc > 0)
	  {
	    new_argv[i + argc] = argv[argc];
	    --argc;
	  }

# ifdef __EMX__
	pid = spawnvpe (P_NOWAIT, shell, new_argv, envp);
	if (pid >= 0)
          break;
# else
	execvp (shell, new_argv);
# endif
	if (errno == ENOENT)
	  error (NILF, _("%s: Shell program not found"), shell);
	else
	  perror_with_name ("execvp: ", shell);
	break;
      }

# ifdef __EMX__

     char **argv, **envp;
{
  char *shell, *path;
  PATH_VAR (program);
  register char **ep;

  shell = path = 0;
  for (ep = envp; *ep != 0; ++ep)
    {
      if (shell == 0 && !strncmp(*ep, "SHELL=", 6))
	shell = &(*ep)[6];
      else if (path == 0 && !strncmp(*ep, "PATH=", 5))
	path = &(*ep)[5];
      else if (path != 0 && shell != 0)
	break;
    }

  /* Be the user, permanently.  */
  child_access ();

  if (!search_path (argv[0], path, program))
    error ("%s: Command not found", argv[0]);
  else
    {
      /* Run the program.  */
      execve (program, argv, envp);

      if (errno == ENOEXEC)
	{
	  PATH_VAR (shell_program);
	  char *shell_path;
	  if (shell == 0)
	    shell_path = default_shell;
	  else
	    {
	      if (search_path (shell, path, shell_program))
		shell_path = shell_program;
	      else
		{
		  shell_path = 0;
		  error ("%s: Shell program not found", shell);
		}
	    }

	  if (shell_path != 0)
	    {
	      char **new_argv;
	      int argc;

	      argc = 1;
	      while (argv[argc] != 0)
		++argc;

	      new_argv = (char **) alloca ((1 + argc + 1) * sizeof (char *));
	      new_argv[0] = shell_path;
	      new_argv[1] = program;
	      while (argc > 0)
		{
		  new_argv[1 + argc] = argv[argc];
		  --argc;
		}

	      execve (shell_path, new_argv, envp);
	      perror_with_name ("execve: ", shell_path);
	    }
	}
      else
	perror_with_name ("execve: ", program);
    }

  _exit (127);

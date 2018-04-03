
#ifndef _AMIGA
# ifdef WINDOWS32
	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;

	if (DuplicateHandle(GetCurrentProcess(),
			    GetStdHandle(STD_INPUT_HANDLE),
			    GetCurrentProcess(),
			    &hIn,
			    0,
			    TRUE,
			    DUPLICATE_SAME_ACCESS) == FALSE) {
	  fatal("create_child_process: DuplicateHandle(In) failed (e=%d)\n",
		GetLastError());
	}
	if (DuplicateHandle(GetCurrentProcess(),
			    GetStdHandle(STD_ERROR_HANDLE),
			    GetCurrentProcess(),
			    &hErr,
			    0,
			    TRUE,
			    DUPLICATE_SAME_ACCESS) == FALSE) {
	  fatal("create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
		GetLastError());
	}

	if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
	  fatal("CreatePipe() failed (e=%d)\n", GetLastError());

	hProcess = process_init_fd(hIn, hChildOutWr, hErr);

	if (!hProcess)
	  fatal("expand_function: process_init_fd() failed\n");
	else
	  process_register(hProcess);

	/* make sure that CreateProcess() has Path it needs */
	sync_Path_environment();

	if (!process_begin(hProcess, argv, envp, argv[0], NULL))
		pid = (int) hProcess;
	else
		fatal("expand_function: unable to launch process (e=%d)\n",
		      process_last_err(hProcess));

	/* set up to read data from child */
	pipedes[0] = _open_osfhandle((long) hChildOutRd, O_RDONLY);

	/* this will be closed almost right away */
	pipedes[1] = _open_osfhandle((long) hChildOutWr, O_APPEND);
# else /* WINDOWS32 */
#  ifdef __MSDOS__
	{
	  /* MSDOS can't fork, but it has `popen'.
	     (Bwt, why isn't `popen' used in all the versions?) */
	  struct variable *sh = lookup_variable ("SHELL", 5);
	  int e;
	  extern int dos_command_running, dos_status;

	  /* Make sure not to bother processing an empty line.  */
	  while (isblank (*text))
	    ++text;
	  if (*text == '\0')
	    break;

	  if (sh)
	    {
	      char buf[PATH_MAX + 7];
	      /* This makes sure $SHELL value is used by $(shell), even
		 though the target environment is not passed to it.  */
	      sprintf (buf, "SHELL=%s", sh->value);
	      putenv (buf);
	    }

	  e = errno;
	  errno = 0;
	  dos_command_running = 1;
	  dos_status = 0;
	  fpipe = popen (text, "rt");
	  dos_command_running = 0;
	  if (!fpipe || dos_status)
	    {
	      pipedes[0] = -1;
	      pid = -1;
	      if (dos_status)
		errno = EINTR;
	      else if (errno == 0)
		errno = ENOMEM;
	      shell_function_completed = -1;
	    }
	  else
	    {
	      pipedes[0] = fileno (fpipe);
	      pid = 42;
	      errno = e;
	      shell_function_completed = 1;
	    }
	}
	if (pipedes[0] < 0)
#  else /* ! __MSDOS__ */
	if (pipe (pipedes) < 0)
#  endif /* __MSDOS__ */
	  {
	    perror_with_name (error_prefix, "pipe");
	    break;
	  }

#  ifndef  __MSDOS__
	pid = vfork ();

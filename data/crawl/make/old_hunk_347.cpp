     INVALID_HANDLE_VALUE if the parent process closed them.  If that
     happens, we open the null device and pass its handle to
     process_begin below as the corresponding handle to inherit.  */
  tmpIn = GetStdHandle(STD_INPUT_HANDLE);
  if (DuplicateHandle (GetCurrentProcess(),
		      tmpIn,
		      GetCurrentProcess(),
		      &hIn,
		      0,
		      TRUE,
		      DUPLICATE_SAME_ACCESS) == FALSE) {
    if ((e = GetLastError()) == ERROR_INVALID_HANDLE) {
      tmpIn = CreateFile("NUL", GENERIC_READ,
			 FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
			 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
      if (tmpIn != INVALID_HANDLE_VALUE
	  && DuplicateHandle(GetCurrentProcess(),
			     tmpIn,
			     GetCurrentProcess(),
			     &hIn,
			     0,
			     TRUE,
			     DUPLICATE_SAME_ACCESS) == FALSE)
	CloseHandle(tmpIn);
    }
    if (hIn == INVALID_HANDLE_VALUE) {
      error (NILF, _("windows32_openpipe: DuplicateHandle(In) failed (e=%ld)\n"), e);
      return -1;
    }
  }
  tmpErr = GetStdHandle(STD_ERROR_HANDLE);
  if (DuplicateHandle(GetCurrentProcess(),
		      tmpErr,
		      GetCurrentProcess(),
		      &hErr,
		      0,
		      TRUE,
		      DUPLICATE_SAME_ACCESS) == FALSE) {
    if ((e = GetLastError()) == ERROR_INVALID_HANDLE) {
      tmpErr = CreateFile("NUL", GENERIC_WRITE,
			  FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
			  OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
      if (tmpErr != INVALID_HANDLE_VALUE
	  && DuplicateHandle(GetCurrentProcess(),
			     tmpErr,
			     GetCurrentProcess(),
			     &hErr,
			     0,
			     TRUE,
			     DUPLICATE_SAME_ACCESS) == FALSE)
	CloseHandle(tmpErr);
    }
    if (hErr == INVALID_HANDLE_VALUE) {
      error (NILF, _("windows32_openpipe: DuplicateHandle(Err) failed (e=%ld)\n"), e);
      return -1;
    }
  }

  if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0)) {
    error (NILF, _("CreatePipe() failed (e=%ld)\n"), GetLastError());
    return -1;
  }

  hProcess = process_init_fd(hIn, hChildOutWr, hErr);

  if (!hProcess) {
    error (NILF, _("windows32_openpipe(): process_init_fd() failed\n"));
    return -1;
  }

  /* make sure that CreateProcess() has Path it needs */
  sync_Path_environment();
  /* 'sync_Path_environment' may realloc 'environ', so take note of
     the new value.  */
  envp = environ;

  if (!process_begin(hProcess, command_argv, envp, command_argv[0], NULL)) {
    /* register process for wait */
	process_register(hProcess);

    /* set the pid for returning to caller */
	*pid_p = (pid_t) hProcess;

    /* set up to read data from child */
	pipedes[0] = _open_osfhandle((intptr_t) hChildOutRd, O_RDONLY);

    /* this will be closed almost right away */
	pipedes[1] = _open_osfhandle((intptr_t) hChildOutWr, O_APPEND);
	return 0;
  } else {
    /* reap/cleanup the failed process */
	process_cleanup(hProcess);

    /* close handles which were duplicated, they weren't used */
	if (hIn != INVALID_HANDLE_VALUE)
	  CloseHandle(hIn);
	if (hErr != INVALID_HANDLE_VALUE)
	  CloseHandle(hErr);

	/* close pipe handles, they won't be used */
	CloseHandle(hChildOutRd);
	CloseHandle(hChildOutWr);

    return -1;
  }
}
#endif


	char **argv,
	char **envp)
{
  HANDLE hIn = INVALID_HANDLE_VALUE;
  HANDLE hOut = INVALID_HANDLE_VALUE;
  HANDLE hErr = INVALID_HANDLE_VALUE;
  HANDLE hProcess, tmpIn, tmpOut, tmpErr;
  DWORD e;

  if (proc_index >= MAXIMUM_WAIT_OBJECTS) {
	DB (DB_JOBS, ("process_easy: All process slots used up\n"));
	return INVALID_HANDLE_VALUE;
  }
  /* Standard handles returned by GetStdHandle can be NULL or
     INVALID_HANDLE_VALUE if the parent process closed them.  If that
     happens, we open the null device and pass its handle to
     CreateProcess as the corresponding handle to inherit.  */
  tmpIn = GetStdHandle(STD_INPUT_HANDLE);
  if (DuplicateHandle(GetCurrentProcess(),
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
      fprintf(stderr, "process_easy: DuplicateHandle(In) failed (e=%ld)\n", e);
      return INVALID_HANDLE_VALUE;
    }
  }
  tmpOut = GetStdHandle (STD_OUTPUT_HANDLE);
  if (DuplicateHandle(GetCurrentProcess(),
		      tmpOut,
		      GetCurrentProcess(),
		      &hOut,
		      0,
		      TRUE,
		      DUPLICATE_SAME_ACCESS) == FALSE) {
    if ((e = GetLastError()) == ERROR_INVALID_HANDLE) {
      tmpOut = CreateFile("NUL", GENERIC_WRITE,
			  FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
			  OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
      if (tmpOut != INVALID_HANDLE_VALUE
	  && DuplicateHandle(GetCurrentProcess(),
			     tmpOut,
			     GetCurrentProcess(),
			     &hOut,
			     0,
			     TRUE,
			     DUPLICATE_SAME_ACCESS) == FALSE)
	CloseHandle(tmpOut);
    }
    if (hOut == INVALID_HANDLE_VALUE) {
      fprintf(stderr, "process_easy: DuplicateHandle(Out) failed (e=%ld)\n", e);
      return INVALID_HANDLE_VALUE;
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
      fprintf(stderr, "process_easy: DuplicateHandle(Err) failed (e=%ld)\n", e);
      return INVALID_HANDLE_VALUE;
    }
  }

  hProcess = process_init_fd(hIn, hOut, hErr);

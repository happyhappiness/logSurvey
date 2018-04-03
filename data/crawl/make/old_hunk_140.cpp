  else
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

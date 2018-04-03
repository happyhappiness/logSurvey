  else
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

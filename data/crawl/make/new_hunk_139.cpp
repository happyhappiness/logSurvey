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

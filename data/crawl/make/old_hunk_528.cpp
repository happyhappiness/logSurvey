	char **argv,
	char **envp)
{
  HANDLE hIn;
  HANDLE hOut;
  HANDLE hErr;
  HANDLE hProcess;

  if (proc_index >= MAXIMUM_WAIT_OBJECTS) {
	DB (DB_JOBS, ("process_easy: All process slots used up\n"));
	return INVALID_HANDLE_VALUE;
  }
  if (DuplicateHandle(GetCurrentProcess(),
                      GetStdHandle(STD_INPUT_HANDLE),
                      GetCurrentProcess(),
                      &hIn,
                      0,
                      TRUE,
                      DUPLICATE_SAME_ACCESS) == FALSE) {
    fprintf(stderr,
            "process_easy: DuplicateHandle(In) failed (e=%ld)\n",
            GetLastError());
    return INVALID_HANDLE_VALUE;
  }
  if (DuplicateHandle(GetCurrentProcess(),
                      GetStdHandle(STD_OUTPUT_HANDLE),
                      GetCurrentProcess(),
                      &hOut,
                      0,
                      TRUE,
                      DUPLICATE_SAME_ACCESS) == FALSE) {
    fprintf(stderr,
           "process_easy: DuplicateHandle(Out) failed (e=%ld)\n",
           GetLastError());
    return INVALID_HANDLE_VALUE;
  }
  if (DuplicateHandle(GetCurrentProcess(),
                      GetStdHandle(STD_ERROR_HANDLE),
                      GetCurrentProcess(),
                      &hErr,
                      0,
                      TRUE,
                      DUPLICATE_SAME_ACCESS) == FALSE) {
    fprintf(stderr,
            "process_easy: DuplicateHandle(Err) failed (e=%ld)\n",
            GetLastError());
    return INVALID_HANDLE_VALUE;
  }

  hProcess = process_init_fd(hIn, hOut, hErr);

                      TRUE,
                      DUPLICATE_SAME_ACCESS) == FALSE) {
    fprintf(stderr,
            "process_easy: DuplicateHandle(In) failed (e=%ld)\n",
            GetLastError());
    return INVALID_HANDLE_VALUE;
  }

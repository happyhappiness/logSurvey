                      TRUE,
                      DUPLICATE_SAME_ACCESS) == FALSE) {
    fprintf(stderr,
            "process_easy: DuplicateHandle(Err) failed (e=%d)\n",
            GetLastError());
    return INVALID_HANDLE_VALUE;
  }

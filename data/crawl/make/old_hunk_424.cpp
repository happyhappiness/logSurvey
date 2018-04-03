			     DUPLICATE_SAME_ACCESS) == FALSE)
	CloseHandle(tmpIn);
    }
    if (hIn == INVALID_HANDLE_VALUE)
      fatal (NILF, _("windows32_openpipe: DuplicateHandle(In) failed (e=%ld)\n"), e);
  }
  tmpErr = GetStdHandle(STD_ERROR_HANDLE);
  if (DuplicateHandle(GetCurrentProcess(),

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

			    0,
			    TRUE,
			    DUPLICATE_SAME_ACCESS) == FALSE) {
	  fatal (NILF, "create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
		GetLastError());
	}

	if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
	  fatal (NILF, "CreatePipe() failed (e=%d)\n", GetLastError());

	hProcess = process_init_fd(hIn, hChildOutWr, hErr);

	if (!hProcess)
	  fatal (NILF, "expand_function: process_init_fd() failed\n");
	else
	  process_register(hProcess);


			    0,
			    TRUE,
			    DUPLICATE_SAME_ACCESS) == FALSE) {
	  fatal (NILF, "create_child_process: DuplicateHandle(In) failed (e=%d)\n",
		GetLastError());
	}
	if (DuplicateHandle(GetCurrentProcess(),

		if (envblk) free(envblk);
		return -1;
	} else {
		if (CreateProcess(
			exec_path,
			command_line,

		if (envblk) free(envblk);
		return -1;
	} else {
		DB (DB_JOBS, ("CreateProcess(%s,%s,...)\n",
			exec_path ? exec_path : "NULL",
			command_line ? command_line : "NULL"));
		if (CreateProcess(
			exec_path,
			command_line,

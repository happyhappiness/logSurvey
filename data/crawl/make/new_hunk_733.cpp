
			pproc->last_err = GetLastError();
			pproc->lerrno = E_FORK;
			fprintf(stderr, "process_begin: CreateProcess(%s, %s, ...) failed.\n",
                                exec_path ? exec_path : "NULL", command_line);
			if (envblk) free(envblk);
			free( command_line );
			return(-1);

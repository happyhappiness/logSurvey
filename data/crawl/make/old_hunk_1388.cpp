			pproc->last_err = GetLastError();
			pproc->lerrno = E_FORK;
			fprintf(stderr, "process_begin: CreateProcess(%s, %s, ...) failed.\n", exec_path, command_line);
			free( command_line );
			return(-1);
		}

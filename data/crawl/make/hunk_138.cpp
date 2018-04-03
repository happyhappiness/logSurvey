  */
 long
 process_begin(
-	HANDLE proc,
-	char **argv,
-	char **envp,
-	char *exec_path,
-	char *as_user)
+        HANDLE proc,
+        char **argv,
+        char **envp,
+        char *exec_path,
+        char *as_user)
 {
-	sub_process *pproc = (sub_process *)proc;
-	char *shell_name = 0;
-	int file_not_found=0;
-	HANDLE exec_handle;
-	char exec_fname[MAX_PATH];
-	const char *path_var = NULL;
-	char **ep;
-	char buf[MAX_PATH];
-	DWORD bytes_returned;
-	DWORD flags;
-	char *command_line;
-	STARTUPINFO startInfo;
-	PROCESS_INFORMATION procInfo;
-	char *envblk=NULL;
-	int pass_null_exec_path = 0;
-
-	/*
-	 *  Shell script detection...  if the exec_path starts with #! then
-	 *  we want to exec shell-script-name exec-path, not just exec-path
-	 *  NT doesn't recognize #!/bin/sh or #!/etc/Tivoli/bin/perl.  We do not
-	 *  hard-code the path to the shell or perl or whatever:  Instead, we
-	 *  assume it's in the path somewhere (generally, the NT tools
-	 *  bin directory)
-	 */
-
-	/* Use the Makefile's value of PATH to look for the program to
-	   execute, because it could be different from Make's PATH
-	   (e.g., if the target sets its own value.  */
-	if (envp)
-		for (ep = envp; *ep; ep++) {
-			if (strncmp (*ep, "PATH=", 5) == 0
-			    || strncmp (*ep, "Path=", 5) == 0) {
-				path_var = *ep + 5;
-				break;
-			}
-		}
-	exec_handle = find_file(exec_path, path_var,
-				exec_fname, sizeof(exec_fname));
-
-	/*
-	 * If we couldn't open the file, just assume that Windows will be
-	 * somehow able to find and execute it.  If the first character
-	 * of the command is '/', assume they set SHELL to a Unixy shell
-	 * that have some magic mounts known only to it, and run the whole
-	 * command via $SHELL -c "COMMAND" instead.
-	 */
-	if (exec_handle == INVALID_HANDLE_VALUE) {
-		if (exec_path[0] == '/') {
-			char *new_argv0;
-			char **argvi = argv;
-			int arglen = 0;
-
-			strcpy(buf, variable_expand ("$(SHELL)"));
-			shell_name = &buf[0];
-			strcpy(exec_fname, "-c");
-			/* Construct a single command string in argv[0].  */
-			while (*argvi) {
-				arglen += strlen(*argvi) + 1;
-				argvi++;
-			}
-			new_argv0 = xmalloc(arglen + 1);
-			new_argv0[0] = '\0';
-			for (argvi = argv; *argvi; argvi++) {
-				strcat(new_argv0, *argvi);
-				strcat(new_argv0, " ");
-			}
-			/* Remove the extra blank at the end.  */
-			new_argv0[arglen-1] = '\0';
-			free(argv[0]);
-			argv[0] = new_argv0;
-			argv[1] = NULL;
-		}
-		else
-			file_not_found++;
-	}
-	else {
-		/* Attempt to read the first line of the file */
-		if (ReadFile( exec_handle,
-				buf, sizeof(buf) - 1, /* leave room for trailing NULL */
-				&bytes_returned, 0) == FALSE || bytes_returned < 2) {
-
-			pproc->last_err = GetLastError();
-			pproc->lerrno = E_IO;
-			CloseHandle(exec_handle);
-			return(-1);
-		}
-		if (buf[0] == '#' && buf[1] == '!') {
-			/*
-			 *  This is a shell script...  Change the command line from
-			 *	exec_path args to shell_name exec_path args
-			 */
-			char *p;
-
-			/*  Make sure buf is NULL terminated */
-			buf[bytes_returned] = 0;
-			/*
-			 * Depending on the file system type, etc. the first line
-			 * of the shell script may end with newline or newline-carriage-return
-			 * Whatever it ends with, cut it off.
-			 */
-			p= strchr(buf, '\n');
-			if (p)
-				*p = 0;
-			p = strchr(buf, '\r');
-			if (p)
-				*p = 0;
-
-			/*
-			 *  Find base name of shell
-			 */
-			shell_name = strrchr( buf, '/');
-			if (shell_name) {
-				shell_name++;
-			} else {
-				shell_name = &buf[2];/* skipping "#!" */
-			}
-
-		}
-		CloseHandle(exec_handle);
-	}
-
-	flags = 0;
-
-	if (file_not_found)
-		command_line = make_command_line( shell_name, exec_path, argv);
-	else {
-		/* If exec_fname includes whitespace, CreateProcess
-		   behaves erratically and unreliably, and often fails
-		   if argv[0] also includes whitespace (and thus will
-		   be quoted by make_command_line below).  So in that
-		   case, we don't pass exec_fname as the 1st arg to
-		   CreateProcess, but instead replace argv[0] with
-		   exec_fname (to keep its leading directories and
-		   extension as found by find_file), and pass NULL to
-		   CreateProcess as its 1st arg.  This works around
-		   the bugs in CreateProcess, which are probably
-		   caused by its passing the command to cmd.exe with
-		   some incorrect quoting.  */
-		if (!shell_name
-		    && batch_file_with_spaces(exec_fname)
-		    && _stricmp(exec_path, argv[0]) == 0) {
-			pass_null_exec_path = 1;
-			free (argv[0]);
-			argv[0] = xstrdup(exec_fname);
-		}
-		command_line = make_command_line( shell_name, exec_fname, argv);
-	}
-
-	if ( command_line == NULL ) {
-		pproc->last_err = 0;
-		pproc->lerrno = E_NO_MEM;
-		return(-1);
-	}
-
-	if (envp) {
-		if (arr2envblk(envp, &envblk) ==FALSE) {
-			pproc->last_err = 0;
-			pproc->lerrno = E_NO_MEM;
-			free( command_line );
-			return(-1);
-		}
-	}
-
-	if (shell_name || file_not_found || pass_null_exec_path) {
-		exec_path = 0;	/* Search for the program in %Path% */
-	} else {
-		exec_path = exec_fname;
-	}
-
-	/*
-	 *  Set up inherited stdin, stdout, stderr for child
-	 */
-	GetStartupInfo(&startInfo);
-	startInfo.dwFlags = STARTF_USESTDHANDLES;
-	startInfo.lpReserved = 0;
-	startInfo.cbReserved2 = 0;
-	startInfo.lpReserved2 = 0;
-	startInfo.hStdInput = (HANDLE)pproc->sv_stdin[1];
-	startInfo.hStdOutput = (HANDLE)pproc->sv_stdout[1];
-	startInfo.hStdError = (HANDLE)pproc->sv_stderr[1];
-
-	if (as_user) {
-		if (envblk) free(envblk);
-		return -1;
-	} else {
-		DB (DB_JOBS, ("CreateProcess(%s,%s,...)\n",
-			exec_path ? exec_path : "NULL",
-			command_line ? command_line : "NULL"));
-		if (CreateProcess(
-			exec_path,
-			command_line,
-			NULL,
-			0, /* default security attributes for thread */
-			TRUE, /* inherit handles (e.g. helper pipes, oserv socket) */
-			flags,
-			envblk,
-			0, /* default starting directory */
-			&startInfo,
-			&procInfo) == FALSE) {
-
-			pproc->last_err = GetLastError();
-			pproc->lerrno = E_FORK;
-			fprintf(stderr, "process_begin: CreateProcess(%s, %s, ...) failed.\n",
+        sub_process *pproc = (sub_process *)proc;
+        char *shell_name = 0;
+        int file_not_found=0;
+        HANDLE exec_handle;
+        char exec_fname[MAX_PATH];
+        const char *path_var = NULL;
+        char **ep;
+        char buf[MAX_PATH];
+        DWORD bytes_returned;
+        DWORD flags;
+        char *command_line;
+        STARTUPINFO startInfo;
+        PROCESS_INFORMATION procInfo;
+        char *envblk=NULL;
+        int pass_null_exec_path = 0;
+
+        /*
+         *  Shell script detection...  if the exec_path starts with #! then
+         *  we want to exec shell-script-name exec-path, not just exec-path
+         *  NT doesn't recognize #!/bin/sh or #!/etc/Tivoli/bin/perl.  We do not
+         *  hard-code the path to the shell or perl or whatever:  Instead, we
+         *  assume it's in the path somewhere (generally, the NT tools
+         *  bin directory)
+         */
+
+        /* Use the Makefile's value of PATH to look for the program to
+           execute, because it could be different from Make's PATH
+           (e.g., if the target sets its own value.  */
+        if (envp)
+                for (ep = envp; *ep; ep++) {
+                        if (strncmp (*ep, "PATH=", 5) == 0
+                            || strncmp (*ep, "Path=", 5) == 0) {
+                                path_var = *ep + 5;
+                                break;
+                        }
+                }
+        exec_handle = find_file(exec_path, path_var,
+                                exec_fname, sizeof(exec_fname));
+
+        /*
+         * If we couldn't open the file, just assume that Windows will be
+         * somehow able to find and execute it.  If the first character
+         * of the command is '/', assume they set SHELL to a Unixy shell
+         * that have some magic mounts known only to it, and run the whole
+         * command via $SHELL -c "COMMAND" instead.
+         */
+        if (exec_handle == INVALID_HANDLE_VALUE) {
+                if (exec_path[0] == '/') {
+                        char *new_argv0;
+                        char **argvi = argv;
+                        int arglen = 0;
+
+                        strcpy(buf, variable_expand ("$(SHELL)"));
+                        shell_name = &buf[0];
+                        strcpy(exec_fname, "-c");
+                        /* Construct a single command string in argv[0].  */
+                        while (*argvi) {
+                                arglen += strlen(*argvi) + 1;
+                                argvi++;
+                        }
+                        new_argv0 = xmalloc(arglen + 1);
+                        new_argv0[0] = '\0';
+                        for (argvi = argv; *argvi; argvi++) {
+                                strcat(new_argv0, *argvi);
+                                strcat(new_argv0, " ");
+                        }
+                        /* Remove the extra blank at the end.  */
+                        new_argv0[arglen-1] = '\0';
+                        free(argv[0]);
+                        argv[0] = new_argv0;
+                        argv[1] = NULL;
+                }
+                else
+                        file_not_found++;
+        }
+        else {
+                /* Attempt to read the first line of the file */
+                if (ReadFile( exec_handle,
+                                buf, sizeof(buf) - 1, /* leave room for trailing NULL */
+                                &bytes_returned, 0) == FALSE || bytes_returned < 2) {
+
+                        pproc->last_err = GetLastError();
+                        pproc->lerrno = E_IO;
+                        CloseHandle(exec_handle);
+                        return(-1);
+                }
+                if (buf[0] == '#' && buf[1] == '!') {
+                        /*
+                         *  This is a shell script...  Change the command line from
+                         *      exec_path args to shell_name exec_path args
+                         */
+                        char *p;
+
+                        /*  Make sure buf is NULL terminated */
+                        buf[bytes_returned] = 0;
+                        /*
+                         * Depending on the file system type, etc. the first line
+                         * of the shell script may end with newline or newline-carriage-return
+                         * Whatever it ends with, cut it off.
+                         */
+                        p= strchr(buf, '\n');
+                        if (p)
+                                *p = 0;
+                        p = strchr(buf, '\r');
+                        if (p)
+                                *p = 0;
+
+                        /*
+                         *  Find base name of shell
+                         */
+                        shell_name = strrchr( buf, '/');
+                        if (shell_name) {
+                                shell_name++;
+                        } else {
+                                shell_name = &buf[2];/* skipping "#!" */
+                        }
+
+                }
+                CloseHandle(exec_handle);
+        }
+
+        flags = 0;
+
+        if (file_not_found)
+                command_line = make_command_line( shell_name, exec_path, argv);
+        else {
+                /* If exec_fname includes whitespace, CreateProcess
+                   behaves erratically and unreliably, and often fails
+                   if argv[0] also includes whitespace (and thus will
+                   be quoted by make_command_line below).  So in that
+                   case, we don't pass exec_fname as the 1st arg to
+                   CreateProcess, but instead replace argv[0] with
+                   exec_fname (to keep its leading directories and
+                   extension as found by find_file), and pass NULL to
+                   CreateProcess as its 1st arg.  This works around
+                   the bugs in CreateProcess, which are probably
+                   caused by its passing the command to cmd.exe with
+                   some incorrect quoting.  */
+                if (!shell_name
+                    && batch_file_with_spaces(exec_fname)
+                    && _stricmp(exec_path, argv[0]) == 0) {
+                        pass_null_exec_path = 1;
+                        free (argv[0]);
+                        argv[0] = xstrdup(exec_fname);
+                }
+                command_line = make_command_line( shell_name, exec_fname, argv);
+        }
+
+        if ( command_line == NULL ) {
+                pproc->last_err = 0;
+                pproc->lerrno = E_NO_MEM;
+                return(-1);
+        }
+
+        if (envp) {
+                if (arr2envblk(envp, &envblk) ==FALSE) {
+                        pproc->last_err = 0;
+                        pproc->lerrno = E_NO_MEM;
+                        free( command_line );
+                        return(-1);
+                }
+        }
+
+        if (shell_name || file_not_found || pass_null_exec_path) {
+                exec_path = 0;  /* Search for the program in %Path% */
+        } else {
+                exec_path = exec_fname;
+        }
+
+        /*
+         *  Set up inherited stdin, stdout, stderr for child
+         */
+        GetStartupInfo(&startInfo);
+        startInfo.dwFlags = STARTF_USESTDHANDLES;
+        startInfo.lpReserved = 0;
+        startInfo.cbReserved2 = 0;
+        startInfo.lpReserved2 = 0;
+        startInfo.hStdInput = (HANDLE)pproc->sv_stdin[1];
+        startInfo.hStdOutput = (HANDLE)pproc->sv_stdout[1];
+        startInfo.hStdError = (HANDLE)pproc->sv_stderr[1];
+
+        if (as_user) {
+                if (envblk) free(envblk);
+                return -1;
+        } else {
+                DB (DB_JOBS, ("CreateProcess(%s,%s,...)\n",
+                        exec_path ? exec_path : "NULL",
+                        command_line ? command_line : "NULL"));
+                if (CreateProcess(
+                        exec_path,
+                        command_line,
+                        NULL,
+                        0, /* default security attributes for thread */
+                        TRUE, /* inherit handles (e.g. helper pipes, oserv socket) */
+                        flags,
+                        envblk,
+                        0, /* default starting directory */
+                        &startInfo,
+                        &procInfo) == FALSE) {
+
+                        pproc->last_err = GetLastError();
+                        pproc->lerrno = E_FORK;
+                        fprintf(stderr, "process_begin: CreateProcess(%s, %s, ...) failed.\n",
                                 exec_path ? exec_path : "NULL", command_line);
-			if (envblk) free(envblk);
-			free( command_line );
-			return(-1);
-		}
-	}
-
-	pproc->pid = (pid_t)procInfo.hProcess;
-	/* Close the thread handle -- we'll just watch the process */
-	CloseHandle(procInfo.hThread);
-
-	/* Close the halves of the pipes we don't need */
-	if ((HANDLE)pproc->sv_stdin[1] != INVALID_HANDLE_VALUE)
-	  CloseHandle((HANDLE)pproc->sv_stdin[1]);
-	if ((HANDLE)pproc->sv_stdout[1] != INVALID_HANDLE_VALUE)
-	  CloseHandle((HANDLE)pproc->sv_stdout[1]);
-	if ((HANDLE)pproc->sv_stderr[1] != INVALID_HANDLE_VALUE)
-	  CloseHandle((HANDLE)pproc->sv_stderr[1]);
+                        if (envblk) free(envblk);
+                        free( command_line );
+                        return(-1);
+                }
+        }
+
+        pproc->pid = (pid_t)procInfo.hProcess;
+        /* Close the thread handle -- we'll just watch the process */
+        CloseHandle(procInfo.hThread);
+
+        /* Close the halves of the pipes we don't need */
+        if ((HANDLE)pproc->sv_stdin[1] != INVALID_HANDLE_VALUE)
+          CloseHandle((HANDLE)pproc->sv_stdin[1]);
+        if ((HANDLE)pproc->sv_stdout[1] != INVALID_HANDLE_VALUE)
+          CloseHandle((HANDLE)pproc->sv_stdout[1]);
+        if ((HANDLE)pproc->sv_stderr[1] != INVALID_HANDLE_VALUE)
+          CloseHandle((HANDLE)pproc->sv_stderr[1]);
         pproc->sv_stdin[1] = 0;
         pproc->sv_stdout[1] = 0;
         pproc->sv_stderr[1] = 0;
 
-	free( command_line );
-	if (envblk) free(envblk);
-	pproc->lerrno=0;
-	return 0;
+        free( command_line );
+        if (envblk) free(envblk);
+        pproc->lerrno=0;
+        return 0;
 }
 
 
 
-#if 0	/* unused */
+#if 0   /* unused */
 static DWORD
 proc_stdin_thread(sub_process *pproc)
 {
-	DWORD in_done;
-	for (;;) {
-		if (WriteFile( (HANDLE) pproc->sv_stdin[0], pproc->inp, pproc->incnt,
-					 &in_done, NULL) == FALSE)
-			_endthreadex(0);
-		// This if should never be true for anonymous pipes, but gives
-		// us a chance to change I/O mechanisms later
-		if (in_done < pproc->incnt) {
-			pproc->incnt -= in_done;
-			pproc->inp += in_done;
-		} else {
-			_endthreadex(0);
-		}
-	}
-	return 0; // for compiler warnings only.. not reached
+        DWORD in_done;
+        for (;;) {
+                if (WriteFile( (HANDLE) pproc->sv_stdin[0], pproc->inp, pproc->incnt,
+                                         &in_done, NULL) == FALSE)
+                        _endthreadex(0);
+                // This if should never be true for anonymous pipes, but gives
+                // us a chance to change I/O mechanisms later
+                if (in_done < pproc->incnt) {
+                        pproc->incnt -= in_done;
+                        pproc->inp += in_done;
+                } else {
+                        _endthreadex(0);
+                }
+        }
+        return 0; // for compiler warnings only.. not reached
 }
 
 static DWORD
 proc_stdout_thread(sub_process *pproc)
 {
-	DWORD bufsize = 1024;
-	char c;
-	DWORD nread;
-	pproc->outp = malloc(bufsize);
-	if (pproc->outp == NULL)
-		_endthreadex(0);
-	pproc->outcnt = 0;
-
-	for (;;) {
-		if (ReadFile( (HANDLE)pproc->sv_stdout[0], &c, 1, &nread, NULL)
-					== FALSE) {
-/*			map_windows32_error_to_string(GetLastError());*/
-			_endthreadex(0);
-		}
-		if (nread == 0)
-			_endthreadex(0);
-		if (pproc->outcnt + nread > bufsize) {
-			bufsize += nread + 512;
-			pproc->outp = realloc(pproc->outp, bufsize);
-			if (pproc->outp == NULL) {
-				pproc->outcnt = 0;
-				_endthreadex(0);
-			}
-		}
-		pproc->outp[pproc->outcnt++] = c;
-	}
-	return 0;
+        DWORD bufsize = 1024;
+        char c;
+        DWORD nread;
+        pproc->outp = malloc(bufsize);
+        if (pproc->outp == NULL)
+                _endthreadex(0);
+        pproc->outcnt = 0;
+
+        for (;;) {
+                if (ReadFile( (HANDLE)pproc->sv_stdout[0], &c, 1, &nread, NULL)
+                                        == FALSE) {
+/*                      map_windows32_error_to_string(GetLastError());*/
+                        _endthreadex(0);
+                }
+                if (nread == 0)
+                        _endthreadex(0);
+                if (pproc->outcnt + nread > bufsize) {
+                        bufsize += nread + 512;
+                        pproc->outp = realloc(pproc->outp, bufsize);
+                        if (pproc->outp == NULL) {
+                                pproc->outcnt = 0;
+                                _endthreadex(0);
+                        }
+                }
+                pproc->outp[pproc->outcnt++] = c;
+        }
+        return 0;
 }
 
 static DWORD
 proc_stderr_thread(sub_process *pproc)
 {
-	DWORD bufsize = 1024;
-	char c;
-	DWORD nread;
-	pproc->errp = malloc(bufsize);
-	if (pproc->errp == NULL)
-		_endthreadex(0);
-	pproc->errcnt = 0;
-
-	for (;;) {
-		if (ReadFile( (HANDLE)pproc->sv_stderr[0], &c, 1, &nread, NULL) == FALSE) {
-			map_windows32_error_to_string(GetLastError());
-			_endthreadex(0);
-		}
-		if (nread == 0)
-			_endthreadex(0);
-		if (pproc->errcnt + nread > bufsize) {
-			bufsize += nread + 512;
-			pproc->errp = realloc(pproc->errp, bufsize);
-			if (pproc->errp == NULL) {
-				pproc->errcnt = 0;
-				_endthreadex(0);
-			}
-		}
-		pproc->errp[pproc->errcnt++] = c;
-	}
-	return 0;
+        DWORD bufsize = 1024;
+        char c;
+        DWORD nread;
+        pproc->errp = malloc(bufsize);
+        if (pproc->errp == NULL)
+                _endthreadex(0);
+        pproc->errcnt = 0;
+
+        for (;;) {
+                if (ReadFile( (HANDLE)pproc->sv_stderr[0], &c, 1, &nread, NULL) == FALSE) {
+                        map_windows32_error_to_string(GetLastError());
+                        _endthreadex(0);
+                }
+                if (nread == 0)
+                        _endthreadex(0);
+                if (pproc->errcnt + nread > bufsize) {
+                        bufsize += nread + 512;
+                        pproc->errp = realloc(pproc->errp, bufsize);
+                        if (pproc->errp == NULL) {
+                                pproc->errcnt = 0;
+                                _endthreadex(0);
+                        }
+                }
+                pproc->errp[pproc->errcnt++] = c;
+        }
+        return 0;
 }
 
 

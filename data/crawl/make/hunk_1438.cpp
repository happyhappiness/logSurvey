 	else
 	  error_prefix = "";
 
-#if !defined(__MSDOS__) && !defined(_AMIGA)
+#if !defined(__MSDOS__) && !defined(_AMIGA) 
+# ifdef WIN32
+        saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
+        saAttr.bInheritHandle = TRUE;
+        saAttr.lpSecurityDescriptor = NULL;
+
+        if (DuplicateHandle(GetCurrentProcess(),
+                            GetStdHandle(STD_INPUT_HANDLE),
+                            GetCurrentProcess(),
+                            &hIn,
+                            0,
+                            TRUE,
+                            DUPLICATE_SAME_ACCESS) == FALSE) {
+          fatal("create_child_process: DuplicateHandle(In) failed (e=%d)\n",
+                GetLastError());
+        }
+        if (DuplicateHandle(GetCurrentProcess(),
+                            GetStdHandle(STD_ERROR_HANDLE),
+                            GetCurrentProcess(),
+                            &hErr,
+                            0,
+                            TRUE,
+                            DUPLICATE_SAME_ACCESS) == FALSE) {
+          fatal("create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
+                GetLastError());
+        }
+
+        if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
+          fatal("CreatePipe() failed (e=%d)\n", GetLastError());
+
+        hProcess = process_init_fd(hIn, hChildOutWr, hErr);
+
+        if (!hProcess)
+          fatal("expand_function: process_init_fd() failed\n");
+        else
+          process_register(hProcess);
+
+        /* make sure that CreateProcess() has Path it needs */
+        sync_Path_environment();
+
+        if (!process_begin(hProcess, argv, envp, argv[0], NULL))
+                pid = (int) hProcess;
+        else
+                fatal("expand_function: unable to launch process (e=%d)\n",
+                      process_last_err(hProcess));
+
+        /* set up to read data from child */
+        pipedes[0] = _open_osfhandle((long) hChildOutRd, O_RDONLY);
+
+        /* this will be closed almost right away */
+        pipedes[1] = _open_osfhandle((long) hChildOutWr, O_APPEND);
+# else /* WIN32 */
 	if (pipe (pipedes) < 0)
 	  {
 	    perror_with_name (error_prefix, "pipe");

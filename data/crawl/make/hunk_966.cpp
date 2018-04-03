   if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
     fatal (NILF, _("CreatePipe() failed (e=%d)\n"), GetLastError());
 
-
-
   hProcess = process_init_fd(hIn, hChildOutWr, hErr);
 
   if (!hProcess)
     fatal (NILF, _("windows32_openpipe (): process_init_fd() failed\n"));
 
-  else
-    process_register(hProcess);
-
   /* make sure that CreateProcess() has Path it needs */
   sync_Path_environment();
 
-  if (!process_begin(hProcess, command_argv, envp, command_argv[0], NULL))
+  if (!process_begin(hProcess, command_argv, envp, command_argv[0], NULL)) {
+    /* register process for wait */
+    process_register(hProcess);
+
+    /* set the pid for returning to caller */
     *pid_p = (int) hProcess;
-  else
-    fatal (NILF, _("windows32_openpipe (): unable to launch process (e=%d)\n"),
-	   process_last_err(hProcess));
 
   /* set up to read data from child */
   pipedes[0] = _open_osfhandle((long) hChildOutRd, O_RDONLY);
 
   /* this will be closed almost right away */
   pipedes[1] = _open_osfhandle((long) hChildOutWr, O_APPEND);
+  } else {
+    /* reap/cleanup the failed process */
+	process_cleanup(hProcess);
+
+    /* close handles which were duplicated, they weren't used */
+	CloseHandle(hIn);
+	CloseHandle(hErr);
+
+	/* close pipe handles, they won't be used */
+	CloseHandle(hChildOutRd);
+	CloseHandle(hChildOutWr);
+
+    /* set status for return */
+    pipedes[0] = pipedes[1] = -1;
+    *pid_p = -1;
+  }
 }
 #endif
 

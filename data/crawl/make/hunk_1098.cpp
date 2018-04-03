   if (!process_begin(hProcess, command_argv, envp, command_argv[0], NULL))
     *pid_p = (int) hProcess;
   else
-    fatal (NILF, "windows32_openpipe (): unable to launch process (e=%d)\n",
+    fatal (NILF, _("windows32_openpipe (): unable to launch process (e=%d)\n"),
 	   process_last_err(hProcess));
 
   /* set up to read data from child */

   FreeConsole ();
 }
 
+/* Construct the name for a named section (a.k.a. `file mapping') object.
+   The returned string is dynamically allocated and needs to be xfree()'d.  */
+static char *
+make_section_name (DWORD pid)
+{
+  return aprintf ("gnu_wget_fake_fork_%lu", pid);
+}
+
+/* This structure is used to hold all the data that is exchanged between
+   parent and child.  */
+struct fake_fork_info
+{
+  HANDLE event;
+  int changedp;
+  char lfilename[MAX_PATH + 1];
+};
+
+/* Determines if we are the child and if so performs the child logic.
+   Return values:
+     < 0  error
+       0  parent
+     > 0  child
+*/
+static int
+fake_fork_child (void)
+{
+  HANDLE section, event;
+  struct fake_fork_info *info;
+  char *name;
+  DWORD le;
+
+  name = make_section_name (GetCurrentProcessId ());
+  section = OpenFileMapping (FILE_MAP_WRITE, FALSE, name);
+  le = GetLastError ();
+  xfree (name);
+  if (!section)
+    {
+      if (le == ERROR_FILE_NOT_FOUND)
+        return 0;   /* Section object does not exist; we are the parent.  */
+      else
+        return -1;
+    }
+
+  info = MapViewOfFile (section, FILE_MAP_WRITE, 0, 0, 0);
+  if (!info)
+    {
+      CloseHandle (section);
+      return -1;
+    }
+
+  event = info->event;
+
+  if (!opt.lfilename)
+    {
+      opt.lfilename = unique_name (DEFAULT_LOGFILE, 0);
+      info->changedp = 1;
+      strncpy (info->lfilename, opt.lfilename, sizeof (info->lfilename));
+      info->lfilename[sizeof (info->lfilename) - 1] = '\0';
+    }
+  else
+    info->changedp = 0;
+
+  UnmapViewOfFile (info);
+  CloseHandle (section);
+
+  /* Inform the parent that we've done our part.  */
+  if (!SetEvent (event))
+    return -1;
+
+  CloseHandle (event);
+  return 1;                     /* We are the child.  */
+}
+
+
+static void
+fake_fork (void)
+{
+  char *cmdline, *args;
+  char exe[MAX_PATH + 1];
+  DWORD exe_len, le;
+  SECURITY_ATTRIBUTES sa;
+  HANDLE section, event, h[2];
+  STARTUPINFO si;
+  PROCESS_INFORMATION pi;
+  struct fake_fork_info *info;
+  char *name;
+  BOOL rv;
+
+  event = section = pi.hProcess = pi.hThread = NULL;
+
+  /* Get command line arguments to pass to the child process.
+     We need to skip the name of the command (what amounts to argv[0]).  */
+  cmdline = GetCommandLine ();
+  if (*cmdline == '"')
+    {
+      args = strchr (cmdline + 1, '"');
+      if (args)
+        ++args;
+    }
+  else
+    args = strchr (cmdline, ' ');
+
+  /* It's ok if args is NULL, that would mean there were no arguments
+     after the command name.  As it is now though, we would never get here
+     if that were true.  */
+
+  /* Get the fully qualified name of our executable.  This is more reliable
+     than using argv[0].  */
+  exe_len = GetModuleFileName (GetModuleHandle (NULL), exe, sizeof (exe));
+  if (!exe_len || (exe_len >= sizeof (exe)))
+    return;
+
+  sa.nLength = sizeof (sa);
+  sa.lpSecurityDescriptor = NULL;
+  sa.bInheritHandle = TRUE;
+
+  /* Create an anonymous inheritable event object that starts out
+     non-signaled.  */
+  event = CreateEvent (&sa, FALSE, FALSE, NULL);
+  if (!event)
+    return;
+
+  /* Creat the child process detached form the current console and in a
+     suspended state.  */
+  memset (&si, 0, sizeof (si));
+  si.cb = sizeof (si);
+  rv = CreateProcess (exe, args, NULL, NULL, TRUE, CREATE_SUSPENDED |
+                      DETACHED_PROCESS, NULL, NULL, &si, &pi);
+  if (!rv)
+    goto cleanup;
+
+  /* Create a named section object with a name based on the process id of
+     the child.  */
+  name = make_section_name (pi.dwProcessId);
+  section =
+      CreateFileMapping (INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0,
+                         sizeof (struct fake_fork_info), name);
+  le = GetLastError();
+  xfree (name);
+  /* Fail if the section object already exists (should not happen).  */
+  if (!section || (le == ERROR_ALREADY_EXISTS))
+    {
+      rv = FALSE;
+      goto cleanup;
+    }
+
+  /* Copy the event handle into the section object.  */
+  info = MapViewOfFile (section, FILE_MAP_WRITE, 0, 0, 0);
+  if (!info)
+    {
+      rv = FALSE;
+      goto cleanup;
+    }
+
+  info->event = event;
+
+  UnmapViewOfFile (info);
+
+  /* Start the child process.  */
+  rv = ResumeThread (pi.hThread);
+  if (!rv)
+    {
+      TerminateProcess (pi.hProcess, (DWORD) -1);
+      goto cleanup;
+    }
+
+  /* Wait for the child to signal to us that it has done its part.  If it
+     terminates before signaling us it's an error.  */
+
+  h[0] = event;
+  h[1] = pi.hProcess;
+  rv = WAIT_OBJECT_0 == WaitForMultipleObjects (2, h, FALSE, 5 * 60 * 1000);
+  if (!rv)
+    goto cleanup;
+
+  info = MapViewOfFile (section, FILE_MAP_READ, 0, 0, 0);
+  if (!info)
+    {
+      rv = FALSE;
+      goto cleanup;
+    }
+
+  /* Ensure string is properly terminated.  */
+  if (info->changedp &&
+      !memchr (info->lfilename, '\0', sizeof (info->lfilename)))
+    {
+      rv = FALSE;
+      goto cleanup;
+    }
+
+  printf (_("Continuing in background, pid %lu.\n"), pi.dwProcessId);
+  if (info->changedp)
+    printf (_("Output will be written to `%s'.\n"), info->lfilename);
+
+  UnmapViewOfFile (info);
+
+cleanup:
+
+  if (event)
+    CloseHandle (event);
+  if (section)
+    CloseHandle (section);
+  if (pi.hThread)
+    CloseHandle (pi.hThread);
+  if (pi.hProcess)
+    CloseHandle (pi.hProcess);
+
+  /* We're the parent.  If all is well, terminate.  */
+  if (rv)
+    exit (0);
+
+  /* We failed, return.  */
+}
+
 void
 fork_to_background (void)
 {
-  ws_hangup ("fork");
+  int rv;
+
+  rv = fake_fork_child ();
+  if (rv < 0)
+    {
+      fprintf (stderr, "fake_fork_child() failed\n");
+      abort ();
+    }
+  else if (rv == 0)
+    {
+      /* We're the parent.  */
+      fake_fork ();
+      /* If fake_fork() returns, it failed.  */
+      fprintf (stderr, "fake_fork() failed\n");
+      abort ();
+    }
+  /* If we get here, we're the child.  */
 }
 
 static BOOL WINAPI

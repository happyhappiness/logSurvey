   debug_flag = ! debug_flag;
 }
 
+#ifdef WINDOWS32
+/*
+ * HANDLE runtime exceptions by avoiding a requestor on the GUI. Capture
+ * exception and print it to stderr instead.
+ *
+ * If debug_flag not set, just print a simple message and exit.
+ * If debug_flag set, print a more verbose message.
+ * If compiled for DEBUG, let exception pass through to GUI so that
+ *   debuggers can attach.
+ */
+LONG WINAPI
+handle_runtime_exceptions( struct _EXCEPTION_POINTERS *exinfo )
+{
+  PEXCEPTION_RECORD exrec = exinfo->ExceptionRecord;
+  LPSTR cmdline = GetCommandLine();
+  LPSTR prg = strtok(cmdline, " ");
+  CHAR errmsg[1024];
+#ifdef USE_EVENT_LOG
+  HANDLE hEventSource;
+  LPTSTR lpszStrings[1];
+#endif
+
+  if (!debug_flag)
+    {
+      sprintf(errmsg, "%s: Interrupt/Exception caught ", prg);
+      sprintf(&errmsg[strlen(errmsg)],
+              "(code = 0x%x, addr = 0x%x)\r\n",
+              exrec->ExceptionCode, exrec->ExceptionAddress);
+      fprintf(stderr, errmsg);
+      exit(255);
+    }
+
+  sprintf(errmsg,
+          "\r\nUnhandled exception filter called from program %s\r\n", prg);
+  sprintf(&errmsg[strlen(errmsg)], "ExceptionCode = %x\r\n",
+          exrec->ExceptionCode);
+  sprintf(&errmsg[strlen(errmsg)], "ExceptionFlags = %x\r\n",
+          exrec->ExceptionFlags);
+  sprintf(&errmsg[strlen(errmsg)], "ExceptionAddress = %x\r\n",
+          exrec->ExceptionAddress);
+
+  if (exrec->ExceptionCode == EXCEPTION_ACCESS_VIOLATION
+      && exrec->NumberParameters >= 2)
+    sprintf(&errmsg[strlen(errmsg)],
+            "Access violation: %s operation at address %x\r\n",
+            exrec->ExceptionInformation[0] ? "write": "read",
+            exrec->ExceptionInformation[1]);
+
+  /* turn this on if we want to put stuff in the event log too */
+#ifdef USE_EVENT_LOG
+  hEventSource = RegisterEventSource(NULL, "GNU Make");
+  lpszStrings[0] = errmsg;
+
+  if (hEventSource != NULL)
+    {
+      ReportEvent(hEventSource,         /* handle of event source */
+                  EVENTLOG_ERROR_TYPE,  /* event type */
+                  0,                    /* event category */
+                  0,                    /* event ID */
+                  NULL,                 /* current user's SID */
+                  1,                    /* strings in lpszStrings */
+                  0,                    /* no bytes of raw data */
+                  lpszStrings,          /* array of error strings */
+                  NULL);                /* no raw data */
+
+      (VOID) DeregisterEventSource(hEventSource);
+    }
+#endif
+
+  /* Write the error to stderr too */
+  fprintf(stderr, errmsg);
+
+#ifdef DEBUG
+  return EXCEPTION_CONTINUE_SEARCH;
+#else
+  exit(255);
+#endif
+}
+#endif  /* WINDOWS32 */
+
+#ifdef  __MSDOS__
+
+static void
+msdos_return_to_initial_directory ()
+{
+  if (directory_before_chdir)
+    chdir (directory_before_chdir);
+}
+#endif
+
 #ifndef _AMIGA
 int
 main (argc, argv, envp)

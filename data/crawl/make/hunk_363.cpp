 
   if (! ISDB (DB_VERBOSE))
     {
-      sprintf(errmsg,
-              _("%s: Interrupt/Exception caught (code = 0x%lx, addr = 0x%p)\n"),
-              prg, exrec->ExceptionCode, exrec->ExceptionAddress);
-      fprintf(stderr, errmsg);
-      exit(255);
+      sprintf (errmsg,
+               _("%s: Interrupt/Exception caught (code = 0x%lx, addr = 0x%p)\n"),
+               prg, exrec->ExceptionCode, exrec->ExceptionAddress);
+      fprintf (stderr, errmsg);
+      exit (255);
     }
 
-  sprintf(errmsg,
-          _("\nUnhandled exception filter called from program %s\nExceptionCode = %lx\nExceptionFlags = %lx\nExceptionAddress = 0x%p\n"),
-          prg, exrec->ExceptionCode, exrec->ExceptionFlags,
-          exrec->ExceptionAddress);
+  sprintf (errmsg,
+           _("\nUnhandled exception filter called from program %s\nExceptionCode = %lx\nExceptionFlags = %lx\nExceptionAddress = 0x%p\n"),
+           prg, exrec->ExceptionCode, exrec->ExceptionFlags,
+           exrec->ExceptionAddress);
 
   if (exrec->ExceptionCode == EXCEPTION_ACCESS_VIOLATION
       && exrec->NumberParameters >= 2)
-    sprintf(&errmsg[strlen(errmsg)],
-            (exrec->ExceptionInformation[0]
-             ? _("Access violation: write operation at address 0x%p\n")
-             : _("Access violation: read operation at address 0x%p\n")),
-            (PVOID)exrec->ExceptionInformation[1]);
+    sprintf (&errmsg[strlen(errmsg)],
+             (exrec->ExceptionInformation[0]
+              ? _("Access violation: write operation at address 0x%p\n")
+              : _("Access violation: read operation at address 0x%p\n")),
+             (PVOID)exrec->ExceptionInformation[1]);
 
   /* turn this on if we want to put stuff in the event log too */
 #ifdef USE_EVENT_LOG
-  hEventSource = RegisterEventSource(NULL, "GNU Make");
+  hEventSource = RegisterEventSource (NULL, "GNU Make");
   lpszStrings[0] = errmsg;
 
   if (hEventSource != NULL)
     {
-      ReportEvent(hEventSource,         /* handle of event source */
-                  EVENTLOG_ERROR_TYPE,  /* event type */
-                  0,                    /* event category */
-                  0,                    /* event ID */
-                  NULL,                 /* current user's SID */
-                  1,                    /* strings in lpszStrings */
-                  0,                    /* no bytes of raw data */
-                  lpszStrings,          /* array of error strings */
-                  NULL);                /* no raw data */
-
-      (VOID) DeregisterEventSource(hEventSource);
+      ReportEvent (hEventSource,         /* handle of event source */
+                   EVENTLOG_ERROR_TYPE,  /* event type */
+                   0,                    /* event category */
+                   0,                    /* event ID */
+                   NULL,                 /* current user's SID */
+                   1,                    /* strings in lpszStrings */
+                   0,                    /* no bytes of raw data */
+                   lpszStrings,          /* array of error strings */
+                   NULL);                /* no raw data */
+
+      (VOID) DeregisterEventSource (hEventSource);
     }
 #endif
 
   /* Write the error to stderr too */
-  fprintf(stderr, errmsg);
+  fprintf (stderr, errmsg);
 
 #ifdef DEBUG
   return EXCEPTION_CONTINUE_SEARCH;
 #else
-  exit(255);
+  exit (255);
   return (255); /* not reached */
 #endif
 }

 
   if (! ISDB (DB_VERBOSE))
     {
-      sprintf(errmsg, _("%s: Interrupt/Exception caught "), prg);
-      sprintf(&errmsg[strlen(errmsg)],
-              "(code = 0x%x, addr = 0x%x)\r\n",
-              exrec->ExceptionCode, exrec->ExceptionAddress);
+      sprintf(errmsg,
+              _("%s: Interrupt/Exception caught (code = 0x%x, addr = 0x%x)\n"),
+              prg, exrec->ExceptionCode, exrec->ExceptionAddress);
       fprintf(stderr, errmsg);
       exit(255);
     }
 
   sprintf(errmsg,
-          _("\r\nUnhandled exception filter called from program %s\r\n"), prg);
-  sprintf(&errmsg[strlen(errmsg)], "ExceptionCode = %x\r\n",
-          exrec->ExceptionCode);
-  sprintf(&errmsg[strlen(errmsg)], "ExceptionFlags = %x\r\n",
-          exrec->ExceptionFlags);
-  sprintf(&errmsg[strlen(errmsg)], "ExceptionAddress = %x\r\n",
+          _("\nUnhandled exception filter called from program %s\nExceptionCode = %x\nExceptionFlags = %x\nExceptionAddress = %x\n"),
+          prg, exrec->ExceptionCode, exrec->ExceptionFlags,
           exrec->ExceptionAddress);
 
   if (exrec->ExceptionCode == EXCEPTION_ACCESS_VIOLATION
       && exrec->NumberParameters >= 2)
     sprintf(&errmsg[strlen(errmsg)],
-            _("Access violation: %s operation at address %x\r\n"),
-            exrec->ExceptionInformation[0] ? _("write"): _("read"),
+            (exrec->ExceptionInformation[0]
+             ? _("Access violation: write operation at address %x\n")
+             : _("Access violation: read operation at address %x\n")),
             exrec->ExceptionInformation[1]);
 
   /* turn this on if we want to put stuff in the event log too */

 		      0,
 		      TRUE,
 		      DUPLICATE_SAME_ACCESS) == FALSE) {
-    fatal (NILF, _("create_child_process: DuplicateHandle(Err) failed (e=%d)\n"),
+    fatal (NILF, _("create_child_process: DuplicateHandle(Err) failed (e=%ld)\n"),
 	   GetLastError());
   }
 
   if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
-    fatal (NILF, _("CreatePipe() failed (e=%d)\n"), GetLastError());
+    fatal (NILF, _("CreatePipe() failed (e=%ld)\n"), GetLastError());
 
   hProcess = process_init_fd(hIn, hChildOutWr, hErr);
 

 		      0,
 		      TRUE,
 		      DUPLICATE_SAME_ACCESS) == FALSE) {
-    fatal (NILF, "create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
+    fatal (NILF, _("create_child_process: DuplicateHandle(Err) failed (e=%d)\n"),
 	   GetLastError());
   }
 
   if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
-    fatal (NILF, "CreatePipe() failed (e=%d)\n", GetLastError());
+    fatal (NILF, _("CreatePipe() failed (e=%d)\n"), GetLastError());
 
 
 
   hProcess = process_init_fd(hIn, hChildOutWr, hErr);
 
   if (!hProcess)
-    fatal (NILF, "windows32_openpipe (): process_init_fd() failed\n");
+    fatal (NILF, _("windows32_openpipe (): process_init_fd() failed\n"));
 
   else
     process_register(hProcess);

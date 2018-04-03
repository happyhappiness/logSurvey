 			    0,
 			    TRUE,
 			    DUPLICATE_SAME_ACCESS) == FALSE) {
-	  fatal("create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
+	  fatal (NILF, "create_child_process: DuplicateHandle(Err) failed (e=%d)\n",
 		GetLastError());
 	}
 
 	if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))
-	  fatal("CreatePipe() failed (e=%d)\n", GetLastError());
+	  fatal (NILF, "CreatePipe() failed (e=%d)\n", GetLastError());
 
 	hProcess = process_init_fd(hIn, hChildOutWr, hErr);
 
 	if (!hProcess)
-	  fatal("expand_function: process_init_fd() failed\n");
+	  fatal (NILF, "expand_function: process_init_fd() failed\n");
 	else
 	  process_register(hProcess);
 

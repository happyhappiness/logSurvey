 windows32_openpipe (int *pipedes, pid_t *pid_p, char **command_argv, char **envp)
 {
   SECURITY_ATTRIBUTES saAttr;
-  HANDLE hIn;
-  HANDLE hErr;
+  HANDLE hIn = INVALID_HANDLE_VALUE;
+  HANDLE hErr = INVALID_HANDLE_VALUE;
   HANDLE hChildOutRd;
   HANDLE hChildOutWr;
-  HANDLE hProcess;
-
+  HANDLE hProcess, tmpIn, tmpErr;
+  DWORD e;
 
   saAttr.nLength = sizeof (SECURITY_ATTRIBUTES);
   saAttr.bInheritHandle = TRUE;
   saAttr.lpSecurityDescriptor = NULL;
 
+  /* Standard handles returned by GetStdHandle can be NULL or
+     INVALID_HANDLE_VALUE if the parent process closed them.  If that
+     happens, we open the null device and pass its handle to
+     process_begin below as the corresponding handle to inherit.  */
+  tmpIn = GetStdHandle(STD_INPUT_HANDLE);
   if (DuplicateHandle (GetCurrentProcess(),
-		      GetStdHandle(STD_INPUT_HANDLE),
+		      tmpIn,
 		      GetCurrentProcess(),
 		      &hIn,
 		      0,
 		      TRUE,
 		      DUPLICATE_SAME_ACCESS) == FALSE) {
-    fatal (NILF, _("windows32_openpipe(): DuplicateHandle(In) failed (e=%ld)\n"),
-	   GetLastError());
-
+    if ((e = GetLastError()) == ERROR_INVALID_HANDLE) {
+      tmpIn = CreateFile("NUL", GENERIC_READ,
+			 FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
+			 OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
+      if (tmpIn != INVALID_HANDLE_VALUE
+	  && DuplicateHandle(GetCurrentProcess(),
+			     tmpIn,
+			     GetCurrentProcess(),
+			     &hIn,
+			     0,
+			     TRUE,
+			     DUPLICATE_SAME_ACCESS) == FALSE)
+	CloseHandle(tmpIn);
+    }
+    if (hIn == INVALID_HANDLE_VALUE)
+      fatal (NILF, _("windows32_openpipe: DuplicateHandle(In) failed (e=%ld)\n"), e);
   }
+  tmpErr = GetStdHandle(STD_ERROR_HANDLE);
   if (DuplicateHandle(GetCurrentProcess(),
-		      GetStdHandle(STD_ERROR_HANDLE),
+		      tmpErr,
 		      GetCurrentProcess(),
 		      &hErr,
 		      0,
 		      TRUE,
 		      DUPLICATE_SAME_ACCESS) == FALSE) {
-    fatal (NILF, _("windows32_open_pipe(): DuplicateHandle(Err) failed (e=%ld)\n"),
-	   GetLastError());
+    if ((e = GetLastError()) == ERROR_INVALID_HANDLE) {
+      tmpErr = CreateFile("NUL", GENERIC_WRITE,
+			  FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
+			  OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
+      if (tmpErr != INVALID_HANDLE_VALUE
+	  && DuplicateHandle(GetCurrentProcess(),
+			     tmpErr,
+			     GetCurrentProcess(),
+			     &hErr,
+			     0,
+			     TRUE,
+			     DUPLICATE_SAME_ACCESS) == FALSE)
+	CloseHandle(tmpErr);
+    }
+    if (hErr == INVALID_HANDLE_VALUE)
+      fatal (NILF, _("windows32_openpipe: DuplicateHandle(Err) failed (e=%ld)\n"), e);
   }
 
   if (!CreatePipe(&hChildOutRd, &hChildOutWr, &saAttr, 0))

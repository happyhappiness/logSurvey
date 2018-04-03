 		die("cannot run browser");
 
 	printf("Launching default browser to display HTML ...\n");
-	ShellExecute(NULL, "open", htmlpath, NULL, "\\", 0);
-
+	r = (int)ShellExecute(NULL, "open", htmlpath, NULL, "\\", SW_SHOWNORMAL);
 	FreeLibrary(shell32);
+	/* see the MSDN documentation referring to the result codes here */
+	if (r <= 32) {
+		die("failed to launch browser for %.*s", MAX_PATH, unixpath);
+	}
 }
 
 int link(const char *oldpath, const char *newpath)
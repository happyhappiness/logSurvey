             *t = '\0';
           }
 #ifdef WINDOWS32
-	else	/* non-Posix shell (cmd.exe etc.) */
-	  {
+        else    /* non-Posix shell (cmd.exe etc.) */
+          {
             const char *f = line;
             char *t = line;
-	    char *tstart = t;
-	    int temp_fd;
-	    FILE* batch = NULL;
-	    int id = GetCurrentProcessId();
-	    PATH_VAR(fbuf);
-
-	    /* Generate a file name for the temporary batch file.  */
-	    sprintf(fbuf, "make%d", id);
-	    *batch_filename = create_batch_file (fbuf, 0, &temp_fd);
-	    DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
-			  *batch_filename));
-
-	    /* Create a FILE object for the batch file, and write to it the
-	       commands to be executed.  Put the batch file in TEXT mode.  */
-	    _setmode (temp_fd, _O_TEXT);
-	    batch = _fdopen (temp_fd, "wt");
-	    fputs ("@echo off\n", batch);
-	    DB (DB_JOBS, (_("Batch file contents:\n\t@echo off\n")));
+            char *tstart = t;
+            int temp_fd;
+            FILE* batch = NULL;
+            int id = GetCurrentProcessId ();
+            PATH_VAR(fbuf);
+
+            /* Generate a file name for the temporary batch file.  */
+            sprintf (fbuf, "make%d", id);
+            *batch_filename = create_batch_file (fbuf, 0, &temp_fd);
+            DB (DB_JOBS, (_("Creating temporary batch file %s\n"),
+                          *batch_filename));
+
+            /* Create a FILE object for the batch file, and write to it the
+               commands to be executed.  Put the batch file in TEXT mode.  */
+            _setmode (temp_fd, _O_TEXT);
+            batch = _fdopen (temp_fd, "wt");
+            fputs ("@echo off\n", batch);
+            DB (DB_JOBS, (_("Batch file contents:\n\t@echo off\n")));
 
             /* Copy the recipe, removing and ignoring interior prefix chars
                [@+-]: they're meaningless in .ONESHELL mode.  */

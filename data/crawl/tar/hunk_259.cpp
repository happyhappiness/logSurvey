 #define MESSAGE_BUFFER_SIZE 100
 
 /* Nonzero if we are verifying at the moment.  */
-int now_verifying = 0;
+bool now_verifying;
 
 /* File descriptor for the file we are diffing.  */
 static int diff_handle;
 
 /* Area for reading file contents into.  */
-static char *diff_buffer = NULL;
-
-/*--------------------------------.
-| Initialize for a diff operation |
-`--------------------------------*/
+static char *diff_buffer;
 
+/* Initialize for a diff operation.  */
 void
 diff_init (void)
 {
-  diff_buffer = (char *) valloc ((unsigned) record_size);
+  diff_buffer = valloc (record_size);
   if (!diff_buffer)
-    FATAL_ERROR ((0, 0,
-		  _("Could not allocate memory for diff buffer of %d bytes"),
-		  record_size));
+    xalloc_die ();
 }
 
-/*------------------------------------------------------------------------.
-| Sigh about something that differs by writing a MESSAGE to stdlis, given |
-| MESSAGE is not NULL.  Also set the exit status if not already.          |
-`------------------------------------------------------------------------*/
-
+/* Sigh about something that differs by writing a MESSAGE to stdlis,
+   given MESSAGE is nonzero.  Also set the exit status if not already.  */
 static void
 report_difference (const char *message)
 {
   if (message)
-    fprintf (stdlis, "%s: %s\n", current_file_name, message);
+    fprintf (stdlis, "%s: %s\n", quotearg_colon (current_stat_info.file_name), message);
 
   if (exit_status == TAREXIT_SUCCESS)
     exit_status = TAREXIT_DIFFERS;
 }
 
-/*-----------------------------------------------------------------------.
-| Takes a buffer returned by read_and_process and does nothing with it.	 |
-`-----------------------------------------------------------------------*/
-
-/* Yes, I know.  SIZE and DATA are unused in this function.  Some compilers
-   may even report it.  That's OK, just relax!  */
-
+/* Take a buffer returned by read_and_process and do nothing with it.  */
 static int
-process_noop (long size, char *data)
+process_noop (size_t size, char *data)
 {
+  /* Yes, I know.  SIZE and DATA are unused in this function.  Some
+     compilers may even report it.  That's OK, just relax!  */
   return 1;
 }
 
-/*---.
-| ?  |
-`---*/
-
 static int
-process_rawdata (long bytes, char *buffer)
+process_rawdata (size_t bytes, char *buffer)
 {
-  int status = read (diff_handle, diff_buffer, (size_t) bytes);
+  ssize_t status = safe_read (diff_handle, diff_buffer, bytes);
   char message[MESSAGE_BUFFER_SIZE];
 
   if (status != bytes)
     {
       if (status < 0)
 	{
-	  WARN ((0, errno, _("Cannot read %s"), current_file_name));
-	  report_difference (NULL);
+	  read_error (current_stat_info.file_name);
+	  report_difference (0);
 	}
       else
 	{
-	  sprintf (message, _("Could only read %d of %ld bytes"),
-		   status, bytes);
+	  sprintf (message, _("Could only read %lu of %lu bytes"),
+		   (unsigned long) status, (unsigned long) bytes);
 	  report_difference (message);
 	}
       return 0;
     }
 
-  if (memcmp (buffer, diff_buffer, (size_t) bytes))
+  if (memcmp (buffer, diff_buffer, bytes))
     {
-      report_difference (_("Data differs"));
+      report_difference (_("Contents differ"));
       return 0;
     }
 
   return 1;
 }
 
-/*---.
-| ?  |
-`---*/
-
 /* Directory contents, only for GNUTYPE_DUMPDIR.  */
 
 static char *dumpdir_cursor;
 
 static int
-process_dumpdir (long bytes, char *buffer)
+process_dumpdir (size_t bytes, char *buffer)
 {
-  if (memcmp (buffer, dumpdir_cursor, (size_t) bytes))
+  if (memcmp (buffer, dumpdir_cursor, bytes))
     {
-      report_difference (_("Data differs"));
+      report_difference (_("Contents differ"));
       return 0;
     }
 

   for (; dp->accumulated >= dot_bytes; dp->accumulated -= dot_bytes)
     {
       if (dp->dots == 0)
-	logprintf (LOG_VERBOSE, "\n%5ldK", (long) (dp->rows * row_bytes / 1024));
+	logprintf (LOG_VERBOSE, "\n%6sK",
+		   number_to_static_string (dp->rows * ROW_BYTES / 1024));
 
       if (dp->dots % opt.dot_spacing == 0)
 	logputs (LOG_VERBOSE, " ");

      unsigned int length;
 {
   if (warn_undefined_variables_flag)
-    {
-      static const char warnmsg[] = "warning: undefined variable `%.*s'";
-      if (reading_filename != 0)
-	makefile_error (reading_filename, *reading_lineno_ptr,
-			warnmsg, length, name);
-      else
-	error (warnmsg, length, name);
-    }
+    error (reading_file,
+           "warning: undefined variable `%.*s'", (int)length, name);
 }
 
 /* Expand a simple reference to variable NAME, which is LENGTH chars long.  */

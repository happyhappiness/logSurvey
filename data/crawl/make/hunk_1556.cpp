   construct_include_path (include_directories == 0 ? (char **) 0
 			  : include_directories->list);
 
+  /* Figure out where we are now, after chdir'ing.  */
+  if (directories == 0)
+    /* We didn't move, so we're still in the same place.  */
+    starting_directory = current_directory;
+  else
+    {
+      if (getcwd (current_directory, GET_PATH_MAX) == 0)
+	{
+#ifdef	HAVE_GETCWD
+	  perror_with_name ("getcwd: ", "");
+#else
+	  error ("getwd: %s", current_directory);
+#endif
+	  starting_directory = 0;
+	}
+      else
+	starting_directory = current_directory;
+    }
+
   /* Tell the user where he is.  */
 
   if (print_directory_flag)

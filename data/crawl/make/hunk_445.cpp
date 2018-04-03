 #else
       if (getcwd (current_directory, GET_PATH_MAX) == 0)
 #endif
-	{
-#ifdef	HAVE_GETCWD
-	  perror_with_name ("getcwd", "");
+        {
+#ifdef  HAVE_GETCWD
+          perror_with_name ("getcwd", "");
 #else
-	  error (NILF, "getwd: %s", current_directory);
+          error (NILF, "getwd: %s", current_directory);
 #endif
-	  starting_directory = 0;
-	}
+          starting_directory = 0;
+        }
       else
-	starting_directory = current_directory;
+        starting_directory = current_directory;
     }
 
   define_variable_cname ("CURDIR", current_directory, o_file, 0);

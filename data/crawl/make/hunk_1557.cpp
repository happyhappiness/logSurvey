   else
     printf ("%s[%u]: %s ", program, makelevel, message);
 
-  if (getcwd (pwdbuf, GET_PATH_MAX) == 0)
-    {
-#ifdef	HAVE_GETCWD
-      perror_with_name ("getcwd: ", "");
-#else
-      error ("getwd: %s", pwdbuf);
-#endif
-      puts ("an unknown directory");
-    }
+  if (starting_directory == 0)
+    puts ("an unknown directory");
   else
-    printf ("directory `%s'\n", pwdbuf);
+    printf ("directory `%s'\n", starting_directory);
 }

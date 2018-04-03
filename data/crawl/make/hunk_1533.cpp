   if (! debug_flag)
     return;
 
-  printf ("%s access: user %d (real %d), group %d (real %d)\n",
-	  flavor, geteuid (), getuid (), getegid (), getgid ());
-  fflush (stdout);
+  /* All the other debugging messages go to stdout,
+     but we write this one to stderr because it might be
+     run in a child fork whose stdout is piped.  */
+
+  fprintf (stderr, "%s access: user %d (real %d), group %d (real %d)\n",
+	   flavor, geteuid (), getuid (), getegid (), getgid ());
+  fflush (stderr);
 }
 
 

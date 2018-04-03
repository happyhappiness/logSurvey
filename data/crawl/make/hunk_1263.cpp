 	printf (" %s", dep_name (d));
       putchar ('\n');
     }
-  if (f->last_mtime == (time_t) 0)
+  if (f->last_mtime == 0)
     puts ("#  Modification time never checked.");
-  else if (f->last_mtime == (time_t) -1)
+  else if (f->last_mtime == (FILE_TIMESTAMP) -1)
     puts ("#  File does not exist.");
   else
-    printf ("#  Last modified %.24s (%ld)\n",
-	    ctime (&f->last_mtime), (long int) f->last_mtime);
+    {
+      char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
+      file_timestamp_sprintf (buf, f->last_mtime);
+      printf ("#  Last modified %s\n", buf);
+    }
   printf ("#  File has%s been updated.\n",
 	  f->updated ? "" : " not");
   switch (f->command_state)

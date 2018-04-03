 	printf (" %s", dep_name (d));
       putchar ('\n');
     }
-  if (f->last_mtime == 0)
+  if (f->last_mtime == UNKNOWN_MTIME)
     puts (_("#  Modification time never checked."));
-  else if (f->last_mtime == (FILE_TIMESTAMP) -1)
+  else if (f->last_mtime == NONEXISTENT_MTIME)
     puts (_("#  File does not exist."));
+  else if (f->last_mtime == OLD_MTIME)
+    puts (_("#  File is very old."));
   else
     {
       char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];

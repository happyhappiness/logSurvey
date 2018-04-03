       file_timestamp_sprintf (buf, f->last_mtime);
       printf (_("#  Last modified %s\n"), buf);
     }
-  printf (_("#  File has%s been updated.\n"),
-	  f->updated ? "" : _(" not"));
+  puts (f->updated
+        ? _("#  File has been updated.") : _("#  File has not been updated."));
   switch (f->command_state)
     {
     case cs_running:

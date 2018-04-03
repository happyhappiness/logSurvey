   putchar ('\n');
 
   if (f->precious)
-    puts ("#  Precious file (dependency of .PRECIOUS).");
+    puts (_("#  Precious file (dependency of .PRECIOUS)."));
   if (f->phony)
-    puts ("#  Phony target (dependency of .PHONY).");
+    puts (_("#  Phony target (dependency of .PHONY)."));
   if (f->cmd_target)
-    puts ("#  Command-line target.");
+    puts (_("#  Command-line target."));
   if (f->dontcare)
-    puts ("#  A default or MAKEFILES makefile.");
-  printf ("#  Implicit rule search has%s been done.\n",
-	  f->tried_implicit ? "" : " not");
+    puts (_("#  A default or MAKEFILES makefile."));
+  printf (_("#  Implicit rule search has%s been done.\n"),
+	  f->tried_implicit ? "" : _(" not"));
   if (f->stem != 0)
-    printf ("#  Implicit/static pattern stem: `%s'\n", f->stem);
+    printf (_("#  Implicit/static pattern stem: `%s'\n"), f->stem);
   if (f->intermediate)
-    puts ("#  File is an intermediate dependency.");
+    puts (_("#  File is an intermediate dependency."));
   if (f->also_make != 0)
     {
-      fputs ("#  Also makes:", stdout);
+      fputs (_("#  Also makes:"), stdout);
       for (d = f->also_make; d != 0; d = d->next)
 	printf (" %s", dep_name (d));
       putchar ('\n');
     }
   if (f->last_mtime == 0)
-    puts ("#  Modification time never checked.");
+    puts (_("#  Modification time never checked."));
   else if (f->last_mtime == (FILE_TIMESTAMP) -1)
-    puts ("#  File does not exist.");
+    puts (_("#  File does not exist."));
   else
     {
       char buf[FILE_TIMESTAMP_PRINT_LEN_BOUND + 1];
       file_timestamp_sprintf (buf, f->last_mtime);
-      printf ("#  Last modified %s\n", buf);
+      printf (_("#  Last modified %s\n"), buf);
     }
-  printf ("#  File has%s been updated.\n",
-	  f->updated ? "" : " not");
+  printf (_("#  File has%s been updated.\n"),
+	  f->updated ? "" : _(" not"));
   switch (f->command_state)
     {
     case cs_running:
-      puts ("#  Commands currently running (THIS IS A BUG).");
+      puts (_("#  Commands currently running (THIS IS A BUG)."));
       break;
     case cs_deps_running:
-      puts ("#  Dependencies commands running (THIS IS A BUG).");
+      puts (_("#  Dependencies commands running (THIS IS A BUG)."));
       break;
     case cs_not_started:
     case cs_finished:

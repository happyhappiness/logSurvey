 {
   register char *s;
 
-  fputs ("#  commands to execute", stdout);
+  fputs (_("#  commands to execute"), stdout);
 
   if (cmds->fileinfo.filenm == 0)
-    puts (" (built-in):");
+    puts (_(" (built-in):"));
   else
-    printf (" (from `%s', line %lu):\n",
+    printf (_(" (from `%s', line %lu):\n"),
             cmds->fileinfo.filenm, cmds->fileinfo.lineno);
 
   s = cmds->commands;

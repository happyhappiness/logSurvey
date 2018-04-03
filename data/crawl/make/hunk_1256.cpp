 
   fputs ("#  commands to execute", stdout);
 
-  if (cmds->filename == 0)
+  if (cmds->fileinfo.filenm == 0)
     puts (" (built-in):");
   else
-    printf (" (from `%s', line %u):\n", cmds->filename, cmds->lineno);
+    printf (" (from `%s', line %lu):\n",
+            cmds->fileinfo.filenm, cmds->fileinfo.lineno);
 
   s = cmds->commands;
   while (*s != '\0')

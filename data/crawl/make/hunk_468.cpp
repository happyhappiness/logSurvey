   if (cmds->fileinfo.filenm == 0)
     puts (_(" (built-in):"));
   else
-    printf (_(" (from `%s', line %lu):\n"),
+    printf (_(" (from '%s', line %lu):\n"),
             cmds->fileinfo.filenm, cmds->fileinfo.lineno);
 
   s = cmds->commands;
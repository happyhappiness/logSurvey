 {
   const char *s;
 
-  fputs (_("#  commands to execute"), stdout);
+  fputs (_("#  recipe to execute"), stdout);
 
   if (cmds->fileinfo.filenm == 0)
     puts (_(" (built-in):"));

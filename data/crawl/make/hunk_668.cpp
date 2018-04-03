 /* Print out the commands in CMDS.  */
 
 void
-print_commands (struct commands *cmds)
+print_commands (const struct commands *cmds)
 {
-  register char *s;
+  const char *s;
 
   fputs (_("#  commands to execute"), stdout);
 

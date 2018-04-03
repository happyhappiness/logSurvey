      can log the working directory before the command's own error messages
      appear.  */
 
-  message ((just_print_flag || (!(flags & COMMANDS_SILENT) && !silent_flag))
-	   ? (char *) 0 : "%s", p);
+  message (0, (just_print_flag || (!(flags & COMMANDS_SILENT) && !silent_flag))
+	   ? "%s" : (char *) 0, p);
 
   /* Tell update_goal_chain that a command has been started on behalf of
      this target.  It is important that this happens here and not in

     /* If there were no command-line goals, use the default.  */
     if (goals == 0)
       {
-        if (**default_target_name != '\0')
+        if (**default_goal_name != '\0')
           {
             if (default_goal_file == 0 ||
-                strcmp (*default_target_name, default_goal_file->name) != 0)
+                strcmp (*default_goal_name, default_goal_file->name) != 0)
               {
-                default_goal_file = lookup_file (*default_target_name);
+                default_goal_file = lookup_file (*default_goal_name);
 
-                /* In case user set .DEFAULT_TARGET to a non-existent target
+                /* In case user set .DEFAULT_GOAL to a non-existent target
                    name let's just enter this name into the table and let
                    the standard logic sort it out. */
                 if (default_goal_file == 0)
                   {
                     struct nameseq *ns;
-                    char *p = *default_target_name;
+                    char *p = *default_goal_name;
 
                     ns = multi_glob (
                       parse_file_seq (&p, '\0', sizeof (struct nameseq), 1),
                       sizeof (struct nameseq));
 
-                    /* .DEFAULT_TARGET should contain one target. */
+                    /* .DEFAULT_GOAL should contain one target. */
                     if (ns->next != 0)
-                      fatal (NILF, _(".DEFAULT_TARGET contains more than one target"));
+                      fatal (NILF, _(".DEFAULT_GOAL contains more than one target"));
 
                     default_goal_file = enter_file (ns->name);
 

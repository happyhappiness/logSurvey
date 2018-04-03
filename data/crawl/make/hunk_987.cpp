 
     /* Update the goals.  */
 
-    if (debug_flag)
-      puts (_("Updating goal targets...."));
+    DB (DB_BASIC, (_("Updating goal targets....\n")));
 
     switch (update_goal_chain (goals, 0))
     {

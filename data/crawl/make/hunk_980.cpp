 
       sprintf (cmd, "$ @%s", comname);
 
-      if (debug_flag)
-	printf (_("Executing %s instead\n"), cmd);
+      DB (DB_JOBS, (_("Executing %s instead\n"), cmd));
     }
 
   cmddsc.dsc$w_length = strlen(cmd);
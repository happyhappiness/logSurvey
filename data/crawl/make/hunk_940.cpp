       child->efn = 0;
       child->cstatus = 1;
 
-      if (debug_flag)
-	printf ("BUILTIN [%s][%s]\n", cmd, cmd+8);
+      DB (DB_JOBS, (_("BUILTIN [%s][%s]\n"), cmd, cmd+8));
 
       p = cmd + 8;
 

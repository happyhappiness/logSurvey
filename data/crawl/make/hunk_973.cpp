       job_rfd = -1;
     }
 
-  if (debug_flag)
-    printf (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children);
+  DB (DB_JOBS, (_("Got a SIGCHLD; %u unreaped children.\n"), dead_children));
 }
 
 

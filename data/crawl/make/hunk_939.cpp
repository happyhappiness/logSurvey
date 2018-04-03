   ofile[0] = 0;
   efile[0] = 0;
 
-  if (debug_flag)
-    printf ("child_execute_job (%s)\n", argv);
+  DB (DB_JOBS, ("child_execute_job (%s)\n", argv));
 
   while (isspace (*argv))
     argv++;

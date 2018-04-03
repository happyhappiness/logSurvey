 	    p++;
 	  in_arg = 1;
 
-	  if (debug_flag)
-	    printf ("BUILTIN RM %s\n", p);
+	  DB (DB_JOBS, (_("BUILTIN RM %s\n"), p));
 	  while (*p)
 	    {
 	      switch (*p)

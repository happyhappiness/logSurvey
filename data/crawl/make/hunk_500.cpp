 
   if (ISDB (DB_VERBOSE))
     {
-      printf (_("Reading makefile `%s'"), filename);
+      printf (_("Reading makefile '%s'"), filename);
       if (flags & RM_NO_DEFAULT_GOAL)
 	printf (_(" (no default goal)"));
       if (flags & RM_INCLUDED)

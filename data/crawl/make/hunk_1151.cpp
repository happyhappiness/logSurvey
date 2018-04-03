 
   if (debug_flag)
     {
-      printf ("Reading makefile `%s'", fileinfo.filenm);
+      printf (_("Reading makefile `%s'"), fileinfo.filenm);
       if (flags & RM_NO_DEFAULT_GOAL)
-	printf (" (no default goal)");
+	printf (_(" (no default goal)"));
       if (flags & RM_INCLUDED)
-	printf (" (search path)");
+	printf (_(" (search path)"));
       if (flags & RM_DONTCARE)
-	printf (" (don't care)");
+	printf (_(" (don't care)"));
       if (flags & RM_NO_TILDE)
-	printf (" (no ~ expansion)");
+	printf (_(" (no ~ expansion)"));
       puts ("...");
     }
 

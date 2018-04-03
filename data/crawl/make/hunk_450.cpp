     {
       printf (_("Reading makefile '%s'"), filename);
       if (flags & RM_NO_DEFAULT_GOAL)
-	printf (_(" (no default goal)"));
+        printf (_(" (no default goal)"));
       if (flags & RM_INCLUDED)
-	printf (_(" (search path)"));
+        printf (_(" (search path)"));
       if (flags & RM_DONTCARE)
-	printf (_(" (don't care)"));
+        printf (_(" (don't care)"));
       if (flags & RM_NO_TILDE)
-	printf (_(" (no ~ expansion)"));
+        printf (_(" (no ~ expansion)"));
       puts ("...");
     }
 

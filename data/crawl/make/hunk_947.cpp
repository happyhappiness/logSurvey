   dnam->nam$l_rsa = dir->d_result;
   dnam->nam$b_rss = MAXNAMLEN;
 
-  if (debug_flag)
-    printf (".");
+  DB (DB_VERBOSE, ("."));
 
   if (!((i = sys$search (dfab)) & 1))
     {
-      if (debug_flag)
-	printf ("sys$search failed with %d\n", i);
+      DB (DB_VERBOSE, (_("sys$search failed with %d\n"), i));
       return (NULL);
     }
 

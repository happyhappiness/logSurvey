     fputs (_("no"), stdout);
   else
     printf ("%u", impossible);
-  printf (_(" impossibilities in %u directories.\n"), dirs);
+  printf (_(" impossibilities in %lu directories.\n"), directories.ht_fill);
 }
 
 /* Hooks for globbing.  */

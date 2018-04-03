 
   fputs ("\n# ", stdout);
   if (files == 0)
-    fputs ("No", stdout);
+    fputs (_("No"), stdout);
   else
     printf ("%u", files);
-  fputs (" files, ", stdout);
+  fputs (_(" files, "), stdout);
   if (impossible == 0)
-    fputs ("no", stdout);
+    fputs (_("no"), stdout);
   else
     printf ("%u", impossible);
-  printf (" impossibilities in %u directories.\n", dirs);
+  printf (_(" impossibilities in %u directories.\n"), dirs);
 }
 
 /* Hooks for globbing.  */

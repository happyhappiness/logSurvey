   if (print_data_base_flag)
     fputs ("# ", stdout);
 
-  if (makelevel == 0)
-    printf ("%s: ", program);
-  else
-    printf ("%s[%u]: ", program, makelevel);
-
   /* Use entire sentences to give the translators a fighting chance.  */
 
-  if (starting_directory == 0)
-    if (entering)
-      puts (_("Entering an unknown directory"));
+  if (makelevel == 0)
+    if (starting_directory == 0)
+      if (entering)
+        printf (_("%s: Entering an unknown directory"), program);
+      else
+        printf (_("%s: Leaving an unknown directory"), program);
     else
-      puts (_("Leaving an unknown directory"));
+      if (entering)
+        printf (_("%s: Entering directory `%s'\n"),
+                program, starting_directory);
+      else
+        printf (_("%s: Leaving directory `%s'\n"),
+                program, starting_directory);
   else
-    if (entering)
-      printf (_("Entering directory `%s'\n"), starting_directory);
+    if (starting_directory == 0)
+      if (entering)
+        printf (_("%s[%u]: Entering an unknown directory"),
+                program, makelevel);
+      else
+        printf (_("%s[%u]: Leaving an unknown directory"),
+                program, makelevel);
     else
-      printf (_("Leaving directory `%s'\n"), starting_directory);
+      if (entering)
+        printf (_("%s[%u]: Entering directory `%s'\n"),
+                program, makelevel, starting_directory);
+      else
+        printf (_("%s[%u]: Leaving directory `%s'\n"),
+                program, makelevel, starting_directory);
 }

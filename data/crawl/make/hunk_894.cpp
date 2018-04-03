     fputs ("# ", stdout);
 
   if (makelevel == 0)
-    printf ("%s: %s ", program, msg);
+    printf ("%s: ", program);
   else
-    printf ("%s[%u]: %s ", program, makelevel, msg);
+    printf ("%s[%u]: ", program, makelevel);
+
+  /* Use entire sentences to give the translators a fighting chance.  */
 
   if (starting_directory == 0)
-    puts (_("an unknown directory"));
+    if (entering)
+      puts (_("Entering an unknown directory"));
+    else
+      puts (_("Leaving an unknown directory"));
   else
-    printf (_("directory `%s'\n"), starting_directory);
+    if (entering)
+      printf (_("Entering directory `%s'\n"), starting_directory);
+    else
+      printf (_("Leaving directory `%s'\n"), starting_directory);
 }

     }
 
   if (rules == 0)
-    puts ("\n# No implicit rules.");
+    puts (_("\n# No implicit rules."));
   else
     {
-      printf ("\n# %u implicit rules, %u", rules, terminal);
+      printf (_("\n# %u implicit rules, %u"), rules, terminal);
 #ifndef	NO_FLOAT
       printf (" (%.1f%%)", (double) terminal / (double) rules * 100.0);
 #else

       printf (" (%.1f%%)", (double) terminal / (double) rules * 100.0);
 #endif
       puts (" terminal.");
-
-      printf ("# %u", subdir);
-#ifndef	NO_FLOAT
-      printf (" (%.1f%%)", (double) subdir / (double) rules * 100.0);
-#endif
-      puts (" reference nonexistent subdirectories.");
     }
 
   if (num_pattern_rules != rules)

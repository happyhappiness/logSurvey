       fputs (_("\n# General ('VPATH' variable) search path:\n# "), stdout);
 
       for (i = 0; path[i] != 0; ++i)
-	printf ("%s%c", path[i],
-		path[i + 1] == 0 ? '\n' : PATH_SEPARATOR_CHAR);
+        printf ("%s%c", path[i],
+                path[i + 1] == 0 ? '\n' : PATH_SEPARATOR_CHAR);
     }
 }

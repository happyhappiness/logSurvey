     }
 
   if (chmod (file_name, mode) != 0)
-    {
-      int e = errno;
-      ERROR ((0, e, _("%s: Cannot change mode to %04lo"),
-	      quotearg_colon (file_name), (unsigned long) mode));
-    }
+    chmod_error_details (file_name, mode);
 }
 
 /* Restore stat attributes (owner, group, mode and times) for

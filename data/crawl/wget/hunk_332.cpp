          token on the next line. */
       if (remaining_chars <= strlen (token))
         {
-          printf ("\n%*c", TABULATION, ' ');
+          if (printf ("\n%*c", TABULATION, ' ') < 0)
+            return -1;
           remaining_chars = line_length - TABULATION;
         }
-      printf ("%s ", token);
+      if (printf ("%s ", token) < 0)
+        return -1;
       remaining_chars -= strlen (token) + 1;  /* account for " " */
       token = strtok (NULL, " ");
     }
 
-  printf ("\n");
+  if (printf ("\n") < 0)
+    return -1;
 
   xfree (line_dup);
+  return 0;
 }
 
 static void

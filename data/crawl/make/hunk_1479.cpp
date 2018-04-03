 /* Print a message on stdout.  */
 
 void
-message (s1, s2, s3, s4, s5, s6)
+message (prefix, s1, s2, s3, s4, s5, s6)
+     int prefix;
      char *s1, *s2, *s3, *s4, *s5, *s6;
 {
-  if (makelevel == 0)
-    printf ("%s: ", program);
-  else
-    printf ("%s[%u]: ", program, makelevel);
-  printf (s1, s2, s3, s4, s5, s6);
-  putchar ('\n');
+  log_working_directory (1);
+
+  if (s1 != 0)
+    {
+      if (prefix)
+	{
+	  if (makelevel == 0)
+	    printf ("%s: ", program);
+	  else
+	    printf ("%s[%u]: ", program, makelevel);
+	}
+      printf (s1, s2, s3, s4, s5, s6);
+      putchar ('\n');
+    }
+
   fflush (stdout);
 }
 

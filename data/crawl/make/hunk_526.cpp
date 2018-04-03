 }
 
 static char *
+func_file (char *o, char **argv, const char *funcname UNUSED)
+{
+  char *fn = argv[0];
+
+  if (fn[0] == '>')
+    {
+      FILE *fp;
+      const char *mode = "w";
+
+      /* We are writing a file.  */
+      ++fn;
+      if (fn[0] == '>')
+        {
+          mode = "a";
+          ++fn;
+        }
+      fn = next_token (fn);
+
+      fp = fopen (fn, mode);
+      if (fp == NULL)
+        fatal (reading_file, _("open: %s: %s"), fn, strerror (errno));
+      else
+        {
+          int l = strlen (argv[1]);
+          int nl = (l == 0 || argv[1][l-1] != '\n');
+
+          if (fputs (argv[1], fp) == EOF || (nl && fputc('\n', fp) == EOF))
+            fatal (reading_file, _("write: %s: %s"), fn, strerror (errno));
+
+          fclose (fp);
+        }
+    }
+  else
+    fatal (reading_file, _("Invalid file operation: %s"), fn);
+
+  return o;
+}
+
+static char *
 func_abspath (char *o, char **argv, const char *funcname UNUSED)
 {
   /* Expand the argument.  */

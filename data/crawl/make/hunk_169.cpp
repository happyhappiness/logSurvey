 
       fp = fopen (fn, mode);
       if (fp == NULL)
-        fatal (reading_file, _("open: %s: %s"), fn, strerror (errno));
+        {
+          const char *err = strerror (errno);
+          OSS (fatal, reading_file, _("open: %s: %s"), fn, err);
+        }
       else
         {
           int l = strlen (argv[1]);
           int nl = (l == 0 || argv[1][l-1] != '\n');
 
           if (fputs (argv[1], fp) == EOF || (nl && fputc ('\n', fp) == EOF))
-            fatal (reading_file, _("write: %s: %s"), fn, strerror (errno));
-
+            {
+              const char *err = strerror (errno);
+              OSS (fatal, reading_file, _("write: %s: %s"), fn, err);
+            }
           fclose (fp);
         }
     }
   else
-    fatal (reading_file, _("Invalid file operation: %s"), fn);
+    OS (fatal, reading_file, _("Invalid file operation: %s"), fn);
 
   return o;
 }

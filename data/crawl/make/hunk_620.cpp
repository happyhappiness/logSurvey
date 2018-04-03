     }
   fputs ("# ", stdout);
   fputs (origin, stdout);
+  if (v->private_var)
+    fputs (" private", stdout);
   if (v->fileinfo.filenm)
     printf (_(" (from `%s', line %lu)"),
             v->fileinfo.filenm, v->fileinfo.lineno);

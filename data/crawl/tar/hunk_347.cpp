 
   if (handle < 0)
     {
-      ERROR ((0, errno, _("Cannot open file %s"), path));
+      open_error (path);
       return;
     }
 
   if (fstat (handle, &stat_data) != 0)
-    ERROR ((0, errno, "%s", path));
+    stat_error (path);
   else
     {
       off_t bytes_left = stat_data.st_size;

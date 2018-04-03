      register struct file *file;
 {
   if (!silent_flag)
-    message ("touch %s\n", file->name);
+    message ("touch %s", file->name);
 
 #ifndef	NO_ARCHIVES
   if (ar_name (file->name))

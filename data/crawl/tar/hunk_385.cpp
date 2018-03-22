   if (file)
     {
       fprintf (file, "%d\n", global_volno);
-      if (fclose (file) == EOF)
-	ERROR ((0, errno, "%s", volno_file_option));
+      if (ferror (file))
+	write_error (volno_file_option);
+      if (fclose (file) != 0)
+	close_error (volno_file_option);
     }
   else
-    ERROR ((0, errno, "%s", volno_file_option));
+    open_error (volno_file_option);
 }
 
 /*-----------------------------------------------------------------------.

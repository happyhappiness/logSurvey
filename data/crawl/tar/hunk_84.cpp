 
   if (!multi_volume_option)
     {
-      enum compress_type type = check_compressed_archive ();
+      bool shortfile;
+      enum compress_type type = check_compressed_archive (&shortfile);
 
       if (type == ct_none)
-	return archive;
-
+	{
+	  if (shortfile)
+	    ERROR ((0, 0, _("This does not look like a tar archive")));
+	  return archive;
+	}
+      
       /* FD is not needed any more */
       rmtclose (archive);
 

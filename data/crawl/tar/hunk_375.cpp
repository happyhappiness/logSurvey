 	  && parent_device != current_stat.st_dev)
 	{
 	  if (verbose_option)
-	    WARN ((0, 0, _("%s: On a different filesystem; not dumped"), p));
+	    WARN ((0, 0, _("%s is on a different filesystem; not dumped"),
+		   quote (p)));
 	  return;
 	}
 
       /* Now output all the files in the directory.  */
 
-      errno = 0;
-
-      directory = opendir (p);
-      if (!directory)
-	{
-	  ERROR ((0, errno, _("Cannot open directory %s"), p));
-	  return;
-	}
-
       /* FIXME: Should speed this up by cd-ing into the dir.  */
 
-      while (entry = readdir (directory), entry)
+      while (errno = 0, (entry = readdir (directory)))
 	{
 	  /* Skip `.', `..', and excluded file names.  */
 

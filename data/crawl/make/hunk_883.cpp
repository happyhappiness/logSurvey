   local (@allfiles);
 
   opendir (DIR, $basedir) || &error ("Couldn't open $basedir: $!\n", 1);
-  @allfiles = grep (!/^\.\.?$/, readdir (DIR) );
+  @allfiles = grep (!/^(\.\.?|CVS|RCS)$/, readdir (DIR) );
   closedir (DIR);
   if ($debug)
   {

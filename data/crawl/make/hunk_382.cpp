   {
     print "Finding tests...\n";
     opendir (SCRIPTDIR, $scriptpath)
-	|| &error ("Couldn't opendir $scriptpath: $!\n");
+        || &error ("Couldn't opendir $scriptpath: $!\n");
     @dirs = grep (!/^(\..*|CVS|RCS)$/, readdir (SCRIPTDIR) );
     closedir (SCRIPTDIR);
     foreach $dir (@dirs)

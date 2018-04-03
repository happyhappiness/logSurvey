       mkdir ("$workpath/$dir", 0777)
            || &error ("Couldn't mkdir $workpath/$dir: $!\n");
       opendir (SCRIPTDIR, "$scriptpath/$dir")
-	  || &error ("Couldn't opendir $scriptpath/$dir: $!\n");
+          || &error ("Couldn't opendir $scriptpath/$dir: $!\n");
       @files = grep (!/^(\..*|CVS|RCS|.*~)$/, readdir (SCRIPTDIR) );
       closedir (SCRIPTDIR);
       foreach $test (@files)
       {
         -d $test and next;
-	push (@TESTS, "$dir/$test");
+        push (@TESTS, "$dir/$test");
       }
     }
   }

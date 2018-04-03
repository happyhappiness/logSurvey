           || &error ("Couldn't mkdir $workpath/$dir: $!\n");
      opendir (SCRIPTDIR, "$scriptpath/$dir")
	  || &error ("Couldn't opendir $scriptpath/$dir: $!\n");
      @files = readdir (SCRIPTDIR);
      closedir (SCRIPTDIR);
      foreach $test (@files)
      {

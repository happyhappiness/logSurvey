           || &error ("Couldn't mkdir $workpath/$dir: $!\n");
      opendir (SCRIPTDIR, "$scriptpath/$dir")
	  || &error ("Couldn't opendir $scriptpath/$dir: $!\n");
      @files = grep (!/^(\.\.?|CVS|RCS)$/, readdir (SCRIPTDIR) );
      closedir (SCRIPTDIR);
      foreach $test (@files)
      {

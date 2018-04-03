    {
      next if ($dir =~ /^(\..*|CVS|RCS)$/ || ! -d "$scriptpath/$dir");
      push (@rmdirs, $dir);
      # VMS can have overlayed file systems, so directories may repeat.
      next if -d "$workpath/$dir";
      mkdir ("$workpath/$dir", 0777)
          || &error ("Couldn't mkdir $workpath/$dir: $!\n");
      opendir (SCRIPTDIR, "$scriptpath/$dir")
          || &error ("Couldn't opendir $scriptpath/$dir: $!\n");
      @files = grep (!/^(\..*|CVS|RCS|.*~)$/, readdir (SCRIPTDIR) );

		die("Too many arguments for list\n") if (defined($cmd[2]));
		mw_list($cmd[1]);
	} elsif ($cmd[0] eq 'import') {
		die("Invalid arguments for import\n")
		    if ($cmd[1] eq EMPTY || defined($cmd[2]));
		mw_import($cmd[1]);
	} elsif ($cmd[0] eq 'option') {
		die("Too many arguments for option\n")
		    if ($cmd[1] eq EMPTY || $cmd[2] eq EMPTY || defined($cmd[3]));
		mw_option($cmd[1],$cmd[2]);
	} elsif ($cmd[0] eq 'push') {
		mw_push($cmd[1]);
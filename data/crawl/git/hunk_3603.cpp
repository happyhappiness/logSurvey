 	if (defined($cmd[0])) {
 		# Line not blank
 		if ($cmd[0] eq "capabilities") {
-			die("Too many arguments for capabilities\n") unless (!defined($cmd[1]));
+			die("Too many arguments for capabilities\n") if (defined($cmd[1]));
 			mw_capabilities();
 		} elsif ($cmd[0] eq "list") {
-			die("Too many arguments for list\n") unless (!defined($cmd[2]));
+			die("Too many arguments for list\n") if (defined($cmd[2]));
 			mw_list($cmd[1]);
 		} elsif ($cmd[0] eq "import") {
-			die("Invalid arguments for import\n") unless ($cmd[1] ne "" && !defined($cmd[2]));
+			die("Invalid arguments for import\n") if ($cmd[1] eq "" || defined($cmd[2]));
 			mw_import($cmd[1]);
 		} elsif ($cmd[0] eq "option") {
-			die("Too many arguments for option\n") unless ($cmd[1] ne "" && $cmd[2] ne "" && !defined($cmd[3]));
+			die("Too many arguments for option\n") if ($cmd[1] eq "" || $cmd[2] eq "" || defined($cmd[3]));
 			mw_option($cmd[1],$cmd[2]);
 		} elsif ($cmd[0] eq "push") {
 			mw_push($cmd[1]);
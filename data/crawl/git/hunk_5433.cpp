 		;
 	else if (!prefixcmp(arg, "--output=")) {
 		options->file = fopen(arg + strlen("--output="), "w");
+		if (!options->file)
+			die_errno("Could not open '%s'", arg + strlen("--output="));
 		options->close_file = 1;
 	} else
 		return 0;
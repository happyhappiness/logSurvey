		die("Unexpected option --remote");
	if (exec)
		die("Option --exec can only be used together with --remote");

	if (!base)
		base = "";

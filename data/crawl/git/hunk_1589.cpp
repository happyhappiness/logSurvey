 	argc = parse_options(argc, argv, NULL, opts, archive_usage, 0);
 
 	if (remote)
-		die("Unexpected option --remote");
+		die(_("Unexpected option --remote"));
 	if (exec)
-		die("Option --exec can only be used together with --remote");
+		die(_("Option --exec can only be used together with --remote"));
 	if (output)
-		die("Unexpected option --output");
+		die(_("Unexpected option --output"));
 
 	if (!base)
 		base = "";
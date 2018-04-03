 	if (argc < 2)
 		usage_with_options(builtin_remote_add_usage, options);
 
+	if (mirror && master)
+		die("specifying a master branch makes no sense with --mirror");
+	if (mirror && track.nr)
+		die("specifying branches to track makes no sense with --mirror");
+
 	name = argv[0];
 	url = argv[1];
 
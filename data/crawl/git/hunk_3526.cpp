 		check_argc(argc, 0, 0);
 		if (!given_config_file && nongit)
 			die("not in a git directory");
+		if (given_config_blob)
+			die("editing blobs is not supported");
 		git_config(git_default_config, NULL);
 		launch_editor(given_config_file ?
 			      given_config_file : git_path("config"),
 			      NULL, NULL);
 	}
 	else if (actions == ACTION_SET) {
 		int ret;
+		check_blob_write();
 		check_argc(argc, 2, 2);
 		value = normalize_value(argv[0], argv[1]);
 		ret = git_config_set_in_file(given_config_file, argv[0], value);

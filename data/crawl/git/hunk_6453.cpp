 		else if (!strcmp(argv[1], "--list") || !strcmp(argv[1], "-l")) {
 			if (argc != 2)
 				usage(git_config_set_usage);
-			if (git_config(show_all_config, NULL) < 0 &&
-					file && errno)
-				die("unable to read config file %s: %s", file,
-				    strerror(errno));
+			if (git_config(show_all_config, NULL) < 0) {
+				if (config_exclusive_filename)
+					die("unable to read config file %s: %s",
+					    config_exclusive_filename, strerror(errno));
+				else
+					die("error processing config file(s)");
+			}
 			return 0;
 		}
 		else if (!strcmp(argv[1], "--global")) {

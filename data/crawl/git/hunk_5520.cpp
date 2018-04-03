 		/* No arguments -- use default remote */
 		remote = remote_get(NULL);
 		result = fetch_one(remote, argc, argv);
+	} else if (multiple) {
+		/* All arguments are assumed to be remotes or groups */
+		for (i = 0; i < argc; i++)
+			if (!add_remote_or_group(argv[i], &list))
+				die("No such remote or remote group: %s", argv[i]);
+		result = fetch_multiple(&list);
 	} else {
 		/* Single remote or group */
 		(void) add_remote_or_group(argv[0], &list);

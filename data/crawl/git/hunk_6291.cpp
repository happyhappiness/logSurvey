 		int groups_found = 0;
 		remote_group.name = argv[i];
 		result = git_config(get_remote_group, &groups_found);
-		if (!groups_found && (i != 1 || strcmp(argv[1], "default")))
-			die("No such remote group: '%s'", argv[i]);
+		if (!groups_found && (i != 1 || strcmp(argv[1], "default"))) {
+			struct remote *remote;
+			if (!remote_is_configured(argv[i]))
+				die("No such remote or remote group: %s",
+				    argv[i]);
+			remote = remote_get(argv[i]);
+			string_list_append(remote->name, remote_group.list);
+		}
 	}
 
 	if (!result && !list.nr  && argc == 2 && !strcmp(argv[1], "default"))
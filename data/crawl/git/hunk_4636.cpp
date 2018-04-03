 		argv[argc] = name;
 		argv[argc + 1] = NULL;
 		if (verbosity >= 0)
-			printf("Fetching %s\n", name);
+			printf(_("Fetching %s\n"), name);
 		if (run_command_v_opt(argv, RUN_GIT_CMD)) {
-			error("Could not fetch %s", name);
+			error(_("Could not fetch %s"), name);
 			result = 1;
 		}
 	}

 	} else if (argc == 1) {
 		/* Allow the user to run an interactive shell */
 		cd_to_homedir();
-		if (access(COMMAND_DIR, R_OK | X_OK) == -1)
-			die("Sorry, the interactive git-shell is not enabled");
+		if (access(COMMAND_DIR, R_OK | X_OK) == -1) {
+			die("Interactive git shell is not enabled.\n"
+			    "hint: ~/" COMMAND_DIR " should exist "
+			    "and have read and execute access.");
+		}
 		run_shell();
 		exit(0);
 	} else if (argc != 3 || strcmp(argv[1], "-c")) {
 	if (!prefixcmp(cmd, "git-")) {
 		cmd += 4;
 		argv[0] = cmd;
-		handle_internal_command(argc, argv, envp);
+		handle_internal_command(argc, argv);
 		die("cannot handle %s internally", cmd);
 	}
 
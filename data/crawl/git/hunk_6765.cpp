 				cmd, argv[0]);
 			exit(1);
 		}
-		help_unknown_cmd(cmd);
+		argv[0] = help_unknown_cmd(cmd);
+		handle_internal_command(argc, argv);
+		execv_dashed_external(argv);
 	}
 
 	fprintf(stderr, "Failed to run command '%s': %s\n",

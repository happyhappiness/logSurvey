 	if (run_command_v_opt(argv_rerere, RUN_GIT_CMD))
 		return error(FAILED_RUN, argv_rerere[0]);
 
+	if (auto_gc && too_many_loose_objects())
+		warning("There are too many unreachable loose objects; "
+			"run 'git prune' to remove them.");
+
 	return 0;
 }
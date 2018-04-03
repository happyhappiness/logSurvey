 	} else
 		add_repack_all_option();
 
-	if (pack_refs && run_command_v_opt(argv_pack_refs, RUN_GIT_CMD))
-		return error(FAILED_RUN, argv_pack_refs[0]);
+	if (pack_refs && run_command_v_opt(pack_refs_cmd.argv, RUN_GIT_CMD))
+		return error(FAILED_RUN, pack_refs_cmd.argv[0]);
 
-	if (run_command_v_opt(argv_reflog, RUN_GIT_CMD))
-		return error(FAILED_RUN, argv_reflog[0]);
+	if (run_command_v_opt(reflog.argv, RUN_GIT_CMD))
+		return error(FAILED_RUN, reflog.argv[0]);
 
-	if (run_command_v_opt(argv_repack, RUN_GIT_CMD))
-		return error(FAILED_RUN, argv_repack[0]);
+	if (run_command_v_opt(repack.argv, RUN_GIT_CMD))
+		return error(FAILED_RUN, repack.argv[0]);
 
 	if (prune_expire) {
-		argv_prune[2] = prune_expire;
+		argv_array_push(&prune, prune_expire);
 		if (quiet)
-			argv_prune[3] = "--no-progress";
-		if (run_command_v_opt(argv_prune, RUN_GIT_CMD))
-			return error(FAILED_RUN, argv_prune[0]);
+			argv_array_push(&prune, "--no-progress");
+		if (run_command_v_opt(prune.argv, RUN_GIT_CMD))
+			return error(FAILED_RUN, prune.argv[0]);
 	}
 
-	if (run_command_v_opt(argv_rerere, RUN_GIT_CMD))
-		return error(FAILED_RUN, argv_rerere[0]);
+	if (run_command_v_opt(rerere.argv, RUN_GIT_CMD))
+		return error(FAILED_RUN, rerere.argv[0]);
 
 	if (auto_gc && too_many_loose_objects())
 		warning(_("There are too many unreachable loose objects; "
 		    name, (uintmax_t)pid);
 	}
 
-	if (pack_refs && run_command_v_opt(pack_refs_cmd.argv, RUN_GIT_CMD))
-		return error(FAILED_RUN, pack_refs_cmd.argv[0]);
-
-	if (run_command_v_opt(reflog.argv, RUN_GIT_CMD))
-		return error(FAILED_RUN, reflog.argv[0]);
+	if (gc_before_repack())
+		return -1;
 
 	if (run_command_v_opt(repack.argv, RUN_GIT_CMD))
 		return error(FAILED_RUN, repack.argv[0]);
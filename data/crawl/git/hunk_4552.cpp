 	args[i] = NULL;
 
 	if (run_command_v_opt(args, RUN_GIT_CMD))
-		die("read-tree failed");
+		die(_("read-tree failed"));
 }
 
 static void restore_state(void)

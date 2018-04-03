 		hook.env = env;
 	}
 
-	ret = start_command(&hook);
+	ret = run_command(&hook);
 	free(argv);
-	if (ret) {
-		warning("Could not spawn %s", argv[0]);
-		return ret;
-	}
-	ret = finish_command(&hook);
-	if (ret == -ERR_RUN_COMMAND_WAITPID_SIGNAL)
-		warning("%s exited due to uncaught signal", argv[0]);
-
 	return ret;
 }

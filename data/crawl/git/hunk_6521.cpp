 	}
 
 	ret = start_command(&hook);
+	free(argv);
 	if (ret) {
 		warning("Could not spawn %s", argv[0]);
 		return ret;
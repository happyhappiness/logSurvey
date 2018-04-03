 	}
 
 	for (i = 0; i < nr; i++) {
-		if (git_config_parse_parameter(argv[i]) < 0) {
-			error("bogus config parameter: %s", argv[i]);
+		if (git_config_parse_parameter(argv[i], fn, data) < 0) {
 			free(argv);
 			free(envw);
 			return -1;

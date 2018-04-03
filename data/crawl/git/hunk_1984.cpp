 	envw = xstrdup(env);
 
 	if (sq_dequote_to_argv(envw, &argv, &nr, &alloc) < 0) {
-		free(envw);
-		return error("bogus format in " CONFIG_DATA_ENVIRONMENT);
+		ret = error("bogus format in " CONFIG_DATA_ENVIRONMENT);
+		goto out;
 	}
 
 	for (i = 0; i < nr; i++) {
 		if (git_config_parse_parameter(argv[i], fn, data) < 0) {
-			free(argv);
-			free(envw);
-			return -1;
+			ret = -1;
+			goto out;
 		}
 	}
 
+out:
 	free(argv);
 	free(envw);
-	return 0;
+	return ret;
 }
 
 static int get_next_char(void)
 			     builtin_config_usage,
 			     PARSE_OPT_STOP_AT_NON_OPTION);
 
-	if (use_global_config + use_system_config + use_local_config + !!given_config_file > 1) {
+	if (use_global_config + use_system_config + use_local_config +
+	    !!given_config_file + !!given_config_blob > 1) {
 		error("only one config file at a time.");
 		usage_with_options(builtin_config_usage, builtin_config_options);
 	}

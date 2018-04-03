 		usage_with_options(builtin_config_usage, builtin_config_options);
 	}
 
+	if (use_local_config && nongit)
+		die(_("--local can only be used inside a git repository"));
+
 	if (given_config_source.file &&
 			!strcmp(given_config_source.file, "-")) {
 		given_config_source.file = NULL;

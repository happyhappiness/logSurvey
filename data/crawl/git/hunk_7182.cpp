 	config_filename = xstrdup(config_filename);
 	out_fd = hold_lock_file_for_update(lock, config_filename, 0);
 	if (out_fd < 0) {
-		ret = error("Could not lock config file!");
+		ret = error("could not lock config file %s", config_filename);
 		goto out;
 	}
 

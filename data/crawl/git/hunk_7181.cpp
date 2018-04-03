 	}
 
 	if (commit_lock_file(lock) < 0) {
-		fprintf(stderr, "Cannot commit config file!\n");
+		error("could not commit config file %s", config_filename);
 		ret = 4;
 		goto out_free;
 	}

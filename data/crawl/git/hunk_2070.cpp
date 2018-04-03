 	fclose(config_file);
 unlock_and_out:
 	if (commit_lock_file(lock) < 0)
-		ret = error("could not write config file %s: %s",
-			    config_filename, strerror(errno));
+		ret = error_errno("could not write config file %s",
+				  config_filename);
 out:
 	free(filename_buf);
 	return ret;
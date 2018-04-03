 	fstat(fileno(config_file), &st);
 
 	if (chmod(get_lock_file_path(lock), st.st_mode & 07777) < 0) {
-		ret = error("chmod on %s failed: %s",
-			    get_lock_file_path(lock), strerror(errno));
+		ret = error_errno("chmod on %s failed",
+				  get_lock_file_path(lock));
 		goto out;
 	}
 

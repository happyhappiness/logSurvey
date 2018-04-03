 		    write_in_full(out_fd, path, length) != length)
 			die("unable to write rerere record");
 	}
-	close(out_fd);
+	if (close(out_fd) != 0)
+		die("unable to write rerere record");
 	return commit_lock_file(&write_lock);
 }
 

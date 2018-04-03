 		if (write_locked_index(&the_index, &index_lock, CLOSE_LOCK))
 			die(_("unable to write new_index file"));
 		commit_style = COMMIT_NORMAL;
-		return index_lock.filename.buf;
+		return get_lock_file_path(&index_lock);
 	}
 
 	/*

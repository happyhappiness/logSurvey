 		if (write_cache(fd, active_cache, active_nr) ||
 		    commit_locked_index(lock_file))
 			die("unable to write new index file");
+
+		err |= run_hook(NULL, "post-checkout", sha1_to_hex(null_sha1),
+				sha1_to_hex(remote_head->old_sha1), "1", NULL);
 	}
 
 	strbuf_release(&reflog_msg);
 	strbuf_release(&branch_top);
 	strbuf_release(&key);
 	strbuf_release(&value);
 	junk_pid = 0;
-	return 0;
+	return err;
 }

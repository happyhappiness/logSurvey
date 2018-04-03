			status |= error("couldn't write %s: %s", log_file,
					strerror(errno));
		} else if (update &&
			   (write_in_full(get_lock_file_fd(lock->lk),
				sha1_to_hex(cb.last_kept_sha1), 40) != 40 ||
			    write_str_in_full(get_lock_file_fd(lock->lk), "\n") != 1 ||
			    close_ref(lock) < 0)) {
			status |= error("couldn't write %s",
					lock->lk->filename.buf);
			rollback_lock_file(&reflog_lock);
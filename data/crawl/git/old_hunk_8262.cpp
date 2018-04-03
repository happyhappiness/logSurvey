		    write_in_full(out_fd, path, length) != length)
			die("unable to write rerere record");
	}
	close(out_fd);
	return commit_lock_file(&write_lock);
}


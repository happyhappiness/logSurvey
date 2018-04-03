			die("too long a refname '%s'", list->name);
		write_or_die(fd, line, len);
	}
	close(fd);
	return commit_lock_file(&packlock);
}


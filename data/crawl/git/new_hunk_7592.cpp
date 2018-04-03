			die("too long a refname '%s'", list->name);
		write_or_die(fd, line, len);
	}
	return commit_lock_file(&packlock);
}


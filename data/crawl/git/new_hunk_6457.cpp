	return lk->fd;
}


NORETURN void unable_to_lock_index_die(const char *path, int err)
{
	if (errno == EEXIST) {
		die("Unable to create '%s.lock': %s.\n\n"
		    "If no other git process is currently running, this probably means a\n"
		    "git process crashed in this repository earlier. Make sure no other git\n"
		    "process is running and remove the file manually to continue.",
		    path, strerror(err));
	} else {
		die("Unable to create '%s.lock': %s", path, strerror(err));
	}
}

int hold_lock_file_for_update(struct lock_file *lk, const char *path, int flags)
{
	int fd = lock_file(lk, path, flags);
	if (fd < 0 && (flags & LOCK_DIE_ON_ERROR))
		unable_to_lock_index_die(path, errno);
	return fd;
}

	return lk->fd;
}

int hold_lock_file_for_update(struct lock_file *lk, const char *path, int flags)
{
	int fd = lock_file(lk, path, flags);
	if (fd < 0 && (flags & LOCK_DIE_ON_ERROR))
		die("unable to create '%s.lock': %s", path, strerror(errno));
	return fd;
}

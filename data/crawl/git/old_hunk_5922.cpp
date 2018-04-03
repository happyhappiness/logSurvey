{
	struct stat st;
	if (lstat(path, &st))
		die("%s: unable to stat (%s)", path, strerror(errno));
	return add_to_index(istate, path, &st, flags);
}


	if (!rc || errno == ENOENT)
		return 0;
	err = errno;
	warning_errno("unable to %s %s", op, file);
	errno = err;
	return rc;
}

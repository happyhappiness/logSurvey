	return fd;
}

static int warn_if_unremovable(const char *op, const char *file, int rc)
{
	if (rc < 0) {

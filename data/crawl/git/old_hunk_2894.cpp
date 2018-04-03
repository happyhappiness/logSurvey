	return tempfile->fd;
}

FILE *fdopen_tempfile(struct tempfile *tempfile, const char *mode)
{
	if (!tempfile->active)

const char *get_tempfile_path(struct tempfile *tempfile)
{
	if (!is_tempfile_active(tempfile))
		die("BUG: get_tempfile_path() called for inactive object");
	return tempfile->filename.buf;
}

int get_tempfile_fd(struct tempfile *tempfile)
{
	if (!is_tempfile_active(tempfile))
		die("BUG: get_tempfile_fd() called for inactive object");
	return tempfile->fd;
}

FILE *get_tempfile_fp(struct tempfile *tempfile)
{
	if (!is_tempfile_active(tempfile))
		die("BUG: get_tempfile_fp() called for inactive object");
	return tempfile->fp;
}


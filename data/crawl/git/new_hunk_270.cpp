				    O_RDWR | O_CREAT | O_EXCL, 0666);
	if (tempfile->fd < 0) {
		deactivate_tempfile(tempfile);
		return NULL;
	}
	activate_tempfile(tempfile);
	if (adjust_shared_perm(tempfile->filename.buf)) {
		int save_errno = errno;
		error("cannot fix permission bits on %s", tempfile->filename.buf);
		delete_tempfile(&tempfile);
		errno = save_errno;
		return NULL;
	}

	return tempfile;
}

struct tempfile *register_tempfile(const char *path)
{
	struct tempfile *tempfile = new_tempfile();
	strbuf_add_absolute_path(&tempfile->filename, path);
	activate_tempfile(tempfile);
	return tempfile;
}

struct tempfile *mks_tempfile_sm(const char *template, int suffixlen, int mode)
{
	struct tempfile *tempfile = new_tempfile();

	strbuf_add_absolute_path(&tempfile->filename, template);
	tempfile->fd = git_mkstemps_mode(tempfile->filename.buf, suffixlen, mode);
	if (tempfile->fd < 0) {
		deactivate_tempfile(tempfile);
		return NULL;
	}
	activate_tempfile(tempfile);
	return tempfile;
}

struct tempfile *mks_tempfile_tsm(const char *template, int suffixlen, int mode)
{
	struct tempfile *tempfile = new_tempfile();
	const char *tmpdir;

	tmpdir = getenv("TMPDIR");
	if (!tmpdir)
		tmpdir = "/tmp";

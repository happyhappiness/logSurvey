	tempfile->fd = git_mkstemps_mode(tempfile->filename.buf, suffixlen, mode);
	if (tempfile->fd < 0) {
		deactivate_tempfile(tempfile);
		return NULL;
	}
	activate_tempfile(tempfile);
	return tempfile;
}

struct tempfile *xmks_tempfile_m(const char *template, int mode)
{
	struct tempfile *tempfile;
	struct strbuf full_template = STRBUF_INIT;

	strbuf_add_absolute_path(&full_template, template);
	tempfile = mks_tempfile_m(full_template.buf, mode);
	if (!tempfile)
		die_errno("Unable to create temporary file '%s'",
			  full_template.buf);

	strbuf_release(&full_template);
	return tempfile;
}

FILE *fdopen_tempfile(struct tempfile *tempfile, const char *mode)

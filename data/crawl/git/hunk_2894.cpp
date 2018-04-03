 	return tempfile->fd;
 }
 
+int mks_tempfile_sm(struct tempfile *tempfile,
+		    const char *template, int suffixlen, int mode)
+{
+	prepare_tempfile_object(tempfile);
+
+	strbuf_add_absolute_path(&tempfile->filename, template);
+	tempfile->fd = git_mkstemps_mode(tempfile->filename.buf, suffixlen, mode);
+	if (tempfile->fd < 0) {
+		strbuf_reset(&tempfile->filename);
+		return -1;
+	}
+	tempfile->owner = getpid();
+	tempfile->active = 1;
+	return tempfile->fd;
+}
+
+int mks_tempfile_tsm(struct tempfile *tempfile,
+		     const char *template, int suffixlen, int mode)
+{
+	const char *tmpdir;
+
+	prepare_tempfile_object(tempfile);
+
+	tmpdir = getenv("TMPDIR");
+	if (!tmpdir)
+		tmpdir = "/tmp";
+
+	strbuf_addf(&tempfile->filename, "%s/%s", tmpdir, template);
+	tempfile->fd = git_mkstemps_mode(tempfile->filename.buf, suffixlen, mode);
+	if (tempfile->fd < 0) {
+		strbuf_reset(&tempfile->filename);
+		return -1;
+	}
+	tempfile->owner = getpid();
+	tempfile->active = 1;
+	return tempfile->fd;
+}
+
+int xmks_tempfile_m(struct tempfile *tempfile, const char *template, int mode)
+{
+	int fd;
+	struct strbuf full_template = STRBUF_INIT;
+
+	strbuf_add_absolute_path(&full_template, template);
+	fd = mks_tempfile_m(tempfile, full_template.buf, mode);
+	if (fd < 0)
+		die_errno("Unable to create temporary file '%s'",
+			  full_template.buf);
+
+	strbuf_release(&full_template);
+	return fd;
+}
+
 FILE *fdopen_tempfile(struct tempfile *tempfile, const char *mode)
 {
 	if (!tempfile->active)

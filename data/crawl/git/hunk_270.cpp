 				    O_RDWR | O_CREAT | O_EXCL, 0666);
 	if (tempfile->fd < 0) {
 		deactivate_tempfile(tempfile);
-		return -1;
+		return NULL;
 	}
 	activate_tempfile(tempfile);
 	if (adjust_shared_perm(tempfile->filename.buf)) {
 		int save_errno = errno;
 		error("cannot fix permission bits on %s", tempfile->filename.buf);
-		delete_tempfile(tempfile);
+		delete_tempfile(&tempfile);
 		errno = save_errno;
-		return -1;
+		return NULL;
 	}
-	return tempfile->fd;
+
+	return tempfile;
 }
 
-void register_tempfile(struct tempfile *tempfile, const char *path)
+struct tempfile *register_tempfile(const char *path)
 {
-	prepare_tempfile_object(tempfile);
+	struct tempfile *tempfile = new_tempfile();
 	strbuf_add_absolute_path(&tempfile->filename, path);
 	activate_tempfile(tempfile);
+	return tempfile;
 }
 
-int mks_tempfile_sm(struct tempfile *tempfile,
-		    const char *template, int suffixlen, int mode)
+struct tempfile *mks_tempfile_sm(const char *template, int suffixlen, int mode)
 {
-	prepare_tempfile_object(tempfile);
+	struct tempfile *tempfile = new_tempfile();
 
 	strbuf_add_absolute_path(&tempfile->filename, template);
 	tempfile->fd = git_mkstemps_mode(tempfile->filename.buf, suffixlen, mode);
 	if (tempfile->fd < 0) {
 		deactivate_tempfile(tempfile);
-		return -1;
+		return NULL;
 	}
 	activate_tempfile(tempfile);
-	return tempfile->fd;
+	return tempfile;
 }
 
-int mks_tempfile_tsm(struct tempfile *tempfile,
-		     const char *template, int suffixlen, int mode)
+struct tempfile *mks_tempfile_tsm(const char *template, int suffixlen, int mode)
 {
+	struct tempfile *tempfile = new_tempfile();
 	const char *tmpdir;
 
-	prepare_tempfile_object(tempfile);
-
 	tmpdir = getenv("TMPDIR");
 	if (!tmpdir)
 		tmpdir = "/tmp";

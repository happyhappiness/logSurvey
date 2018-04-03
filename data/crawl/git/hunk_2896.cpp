 	raise(signo);
 }
 
-/* Make sure errno contains a meaningful value on error */
-int create_tempfile(struct tempfile *tempfile, const char *path)
+/*
+ * Initialize *tempfile if necessary and add it to tempfile_list.
+ */
+static void prepare_tempfile_object(struct tempfile *tempfile)
 {
-	size_t pathlen = strlen(path);
-
 	if (!tempfile_list) {
 		/* One-time initialization */
 		sigchain_push_common(remove_tempfiles_on_signal);
 		atexit(remove_tempfiles_on_exit);
 	}
 
 	if (tempfile->active)
-		die("BUG: create_tempfile called for active object");
+		die("BUG: prepare_tempfile_object called for active object");
 	if (!tempfile->on_list) {
 		/* Initialize *tempfile and add it to tempfile_list: */
 		tempfile->fd = -1;
 		tempfile->fp = NULL;
 		tempfile->active = 0;
 		tempfile->owner = 0;
-		strbuf_init(&tempfile->filename, pathlen);
+		strbuf_init(&tempfile->filename, 0);
 		tempfile->next = tempfile_list;
 		tempfile_list = tempfile;
 		tempfile->on_list = 1;
 	} else if (tempfile->filename.len) {
 		/* This shouldn't happen, but better safe than sorry. */
-		die("BUG: create_tempfile called for improperly-reset object");
+		die("BUG: prepare_tempfile_object called for improperly-reset object");
 	}
+}
+
+/* Make sure errno contains a meaningful value on error */
+int create_tempfile(struct tempfile *tempfile, const char *path)
+{
+	prepare_tempfile_object(tempfile);
 
 	strbuf_add_absolute_path(&tempfile->filename, path);
 	tempfile->fd = open(tempfile->filename.buf, O_RDWR | O_CREAT | O_EXCL, 0666);
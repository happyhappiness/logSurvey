 		return -1;
 	if (close_tempfile_gently(tempfile)) {
 		error(_("could not close '%s'"), tempfile->filename.buf);
-		delete_tempfile(tempfile);
+		delete_tempfile(&tempfile);
 		return -1;
 	}
 	if (stat(tempfile->filename.buf, &st))

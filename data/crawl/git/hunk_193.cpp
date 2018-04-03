 	}
 
 	switch (ce_mode_s_ifmt) {
-	case S_IFREG:
 	case S_IFLNK:
+		new = read_blob_entry(ce, &size);
+		if (!new)
+			return error("unable to read sha1 file of %s (%s)",
+				     path, oid_to_hex(&ce->oid));
+
+		/*
+		 * We can't make a real symlink; write out a regular file entry
+		 * with the symlink destination as its contents.
+		 */
+		if (!has_symlinks || to_tempfile)
+			goto write_file_entry;
+
+		ret = symlink(new, path);
+		free(new);
+		if (ret)
+			return error_errno("unable to create symlink %s", path);
+		break;
+
+	case S_IFREG:
 		/*
 		 * We do not send the blob in case of a retry, so do not
 		 * bother reading it at all.
 		 */
-		if (ce_mode_s_ifmt == S_IFREG && dco && dco->state == CE_RETRY) {
+		if (dco && dco->state == CE_RETRY) {
 			new = NULL;
 			size = 0;
 		} else {

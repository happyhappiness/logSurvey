 			fd = create_file(path, ce->ce_mode);
 		if (fd < 0) {
 			free(new);
-			return error("git-checkout-index: unable to create file %s (%s)",
+			return error("git checkout-index: unable to create file %s (%s)",
 				path, strerror(errno));
 		}
 
 		wrote = write_in_full(fd, new, size);
 		close(fd);
 		free(new);
 		if (wrote != size)
-			return error("git-checkout-index: unable to write file %s", path);
+			return error("git checkout-index: unable to write file %s", path);
 		break;
 	case S_IFLNK:
 		new = read_blob_entry(ce, path, &size);
 		if (!new)
-			return error("git-checkout-index: unable to read sha1 file of %s (%s)",
+			return error("git checkout-index: unable to read sha1 file of %s (%s)",
 				path, sha1_to_hex(ce->sha1));
 		if (to_tempfile || !has_symlinks) {
 			if (to_tempfile) {

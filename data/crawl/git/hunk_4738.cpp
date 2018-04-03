 		}
 
 		if (unlink(dest->buf) && errno != ENOENT)
-			die_errno("failed to unlink '%s'", dest->buf);
+			die_errno(_("failed to unlink '%s'"), dest->buf);
 		if (!option_no_hardlinks) {
 			if (!link(src->buf, dest->buf))
 				continue;
 			if (option_local)
-				die_errno("failed to create link '%s'", dest->buf);
+				die_errno(_("failed to create link '%s'"), dest->buf);
 			option_no_hardlinks = 1;
 		}
 		if (copy_file_with_time(dest->buf, src->buf, 0666))
-			die_errno("failed to copy file to '%s'", dest->buf);
+			die_errno(_("failed to copy file to '%s'"), dest->buf);
 	}
 	closedir(dir);
 }

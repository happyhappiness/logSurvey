 		}
 
 		if (unlink(dest->buf) && errno != ENOENT)
-			die("failed to unlink %s\n", dest->buf);
+			die("failed to unlink %s", dest->buf);
 		if (!option_no_hardlinks) {
 			if (!link(src->buf, dest->buf))
 				continue;
 			if (option_local)
-				die("failed to create link %s\n", dest->buf);
+				die("failed to create link %s", dest->buf);
 			option_no_hardlinks = 1;
 		}
 		if (copy_file(dest->buf, src->buf, 0666))
-			die("failed to copy file to %s\n", dest->buf);
+			die("failed to copy file to %s", dest->buf);
 	}
 	closedir(dir);
 }

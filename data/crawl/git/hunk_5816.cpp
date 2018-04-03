 			if (!link(src->buf, dest->buf))
 				continue;
 			if (option_local)
-				die("failed to create link %s", dest->buf);
+				die_errno("failed to create link '%s'", dest->buf);
 			option_no_hardlinks = 1;
 		}
 		if (copy_file(dest->buf, src->buf, 0666))
-			die("failed to copy file to %s", dest->buf);
+			die_errno("failed to copy file to '%s'", dest->buf);
 	}
 	closedir(dir);
 }

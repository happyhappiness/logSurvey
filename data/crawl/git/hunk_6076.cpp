 		}
 
 		if (unlink(dest->buf) && errno != ENOENT)
-			die("failed to unlink %s", dest->buf);
+			die("failed to unlink %s: %s",
+			    dest->buf, strerror(errno));
 		if (!option_no_hardlinks) {
 			if (!link(src->buf, dest->buf))
 				continue;
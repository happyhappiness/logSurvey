 		}
 
 		if (unlink(dest->buf) && errno != ENOENT)
-			die("failed to unlink %s: %s",
-			    dest->buf, strerror(errno));
+			die_errno("failed to unlink '%s'", dest->buf);
 		if (!option_no_hardlinks) {
 			if (!link(src->buf, dest->buf))
 				continue;

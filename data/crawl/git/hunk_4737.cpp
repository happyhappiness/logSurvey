 		strbuf_setlen(dest, dest_len);
 		strbuf_addstr(dest, de->d_name);
 		if (stat(src->buf, &buf)) {
-			warning ("failed to stat %s\n", src->buf);
+			warning (_("failed to stat %s\n"), src->buf);
 			continue;
 		}
 		if (S_ISDIR(buf.st_mode)) {

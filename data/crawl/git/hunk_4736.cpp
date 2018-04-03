 
 	dir = opendir(src->buf);
 	if (!dir)
-		die_errno("failed to open '%s'", src->buf);
+		die_errno(_("failed to open '%s'"), src->buf);
 
 	if (mkdir(dest->buf, 0777)) {
 		if (errno != EEXIST)
-			die_errno("failed to create directory '%s'", dest->buf);
+			die_errno(_("failed to create directory '%s'"), dest->buf);
 		else if (stat(dest->buf, &buf))
-			die_errno("failed to stat '%s'", dest->buf);
+			die_errno(_("failed to stat '%s'"), dest->buf);
 		else if (!S_ISDIR(buf.st_mode))
-			die("%s exists and is not a directory", dest->buf);
+			die(_("%s exists and is not a directory"), dest->buf);
 	}
 
 	strbuf_addch(src, '/');

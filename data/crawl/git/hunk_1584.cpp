 
 	fd = open(p, O_RDONLY);
 	if (fd < 0)
-		not_found("Cannot open '%s': %s", p, strerror(errno));
+		not_found(hdr, "Cannot open '%s': %s", p, strerror(errno));
 	if (fstat(fd, &sb) < 0)
 		die_errno("Cannot stat '%s'", p);
 
-	hdr_int(content_length, sb.st_size);
-	hdr_str(content_type, the_type);
-	hdr_date(last_modified, sb.st_mtime);
-	end_headers();
+	hdr_int(hdr, content_length, sb.st_size);
+	hdr_str(hdr, content_type, the_type);
+	hdr_date(hdr, last_modified, sb.st_mtime);
+	end_headers(hdr);
 
 	for (;;) {
 		ssize_t n = xread(fd, buf, buf_alloc);

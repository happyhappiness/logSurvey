 
 int read_pack_header(int fd, struct pack_header *header)
 {
-	char *c = (char*)header;
-	ssize_t remaining = sizeof(struct pack_header);
-	do {
-		ssize_t r = xread(fd, c, remaining);
-		if (r <= 0)
-			/* "eof before pack header was fully read" */
-			return PH_ERROR_EOF;
-		remaining -= r;
-		c += r;
-	} while (remaining > 0);
+	if (read_in_full(fd, header, sizeof(*header)) < sizeof(*header))
+		/* "eof before pack header was fully read" */
+		return PH_ERROR_EOF;
+
 	if (header->hdr_signature != htonl(PACK_SIGNATURE))
 		/* "protocol error (pack signature mismatch detected)" */
 		return PH_ERROR_PACK_SIGNATURE;
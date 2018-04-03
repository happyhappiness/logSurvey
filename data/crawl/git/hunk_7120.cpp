 	}
 }
 
-int sha1close(struct sha1file *f, unsigned char *result, int final)
+int sha1close(struct sha1file *f, unsigned char *result, unsigned int flags)
 {
 	int fd;
 	unsigned offset = f->offset;
+
 	if (offset) {
 		SHA1_Update(&f->ctx, f->buffer, offset);
 		sha1flush(f, offset);
 		f->offset = 0;
 	}
-	if (final) {
+	if (flags & (CSUM_CLOSE | CSUM_FSYNC)) {
 		/* write checksum and close fd */
 		SHA1_Final(f->buffer, &f->ctx);
 		if (result)
 			hashcpy(result, f->buffer);
 		sha1flush(f, 20);
+		if (flags & CSUM_FSYNC)
+			fsync_or_die(f->fd, f->name);
 		if (close(f->fd))
 			die("%s: sha1 file error on close (%s)",
 			    f->name, strerror(errno));
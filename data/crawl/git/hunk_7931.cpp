 
 int sha1close(struct sha1file *f, unsigned char *result, int final)
 {
+	int fd;
 	unsigned offset = f->offset;
 	if (offset) {
 		SHA1_Update(&f->ctx, f->buffer, offset);
 		sha1flush(f, offset);
 		f->offset = 0;
 	}
-	if (!final)
-		return 0;	/* only want to flush (no checksum write, no close) */
-	SHA1_Final(f->buffer, &f->ctx);
-	if (result)
-		hashcpy(result, f->buffer);
-	sha1flush(f, 20);
-	if (close(f->fd))
-		die("%s: sha1 file error on close (%s)", f->name, strerror(errno));
+	if (final) {
+		/* write checksum and close fd */
+		SHA1_Final(f->buffer, &f->ctx);
+		if (result)
+			hashcpy(result, f->buffer);
+		sha1flush(f, 20);
+		if (close(f->fd))
+			die("%s: sha1 file error on close (%s)",
+			    f->name, strerror(errno));
+		fd = 0;
+	} else
+		fd = f->fd;
 	free(f);
-	return 0;
+	return fd;
 }
 
 int sha1write(struct sha1file *f, void *buf, unsigned int count)
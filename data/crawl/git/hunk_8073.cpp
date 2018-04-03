 		size = nbuf.len;
 		buf  = nbuf.buf;
 	}
+	write_or_die(fd, buf, size);
+	strbuf_release(&nbuf);
 
-	while (size) {
-		int written = xwrite(fd, buf, size);
-		if (written < 0)
-			die("writing file %s: %s", path, strerror(errno));
-		if (!written)
-			die("out of space writing file %s", path);
-		buf += written;
-		size -= written;
-	}
 	if (close(fd) < 0)
 		die("closing file %s: %s", path, strerror(errno));
-	strbuf_release(&nbuf);
 	return 0;
 }
 
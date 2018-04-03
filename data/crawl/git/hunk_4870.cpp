 		struct strbuf sbuf = STRBUF_INIT;
 		if (strbuf_read(&sbuf, fd, 4096) >= 0)
 			ret = index_mem(sha1, sbuf.buf, sbuf.len, write_object,
-					type, path);
+					type, path, format_check);
 		else
 			ret = -1;
 		strbuf_release(&sbuf);
 	} else if (!size) {
-		ret = index_mem(sha1, NULL, size, write_object, type, path);
+		ret = index_mem(sha1, NULL, size, write_object, type, path,
+				format_check);
 	} else if (size <= SMALL_FILE_SIZE) {
 		char *buf = xmalloc(size);
 		if (size == read_in_full(fd, buf, size))
 			ret = index_mem(sha1, buf, size, write_object, type,
-					path);
+					path, format_check);
 		else
 			ret = error("short read %s", strerror(errno));
 		free(buf);
 	} else {
 		void *buf = xmmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
-		ret = index_mem(sha1, buf, size, write_object, type, path);
+		ret = index_mem(sha1, buf, size, write_object, type, path,
+				format_check);
 		munmap(buf, size);
 	}
 	close(fd);

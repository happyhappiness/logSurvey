 	else {
 		/* Reading from stdin */
 		contents_from = "standard input";
-		buf = NULL;
-		fin_size = 0;
 		mode = 0;
-		while (1) {
-			ssize_t cnt = 8192;
-			buf = xrealloc(buf, fin_size + cnt);
-			cnt = xread(0, buf + fin_size, cnt);
-			if (cnt < 0)
-				die("read error %s from stdin",
-				    strerror(errno));
-			if (!cnt)
-				break;
-			fin_size += cnt;
-		}
-		buf = xrealloc(buf, fin_size + 1);
+		if (strbuf_read(&buf, 0) < 0)
+			die("read error %s from stdin", strerror(errno));
 	}
-	buf[fin_size] = 0;
-	origin->file.ptr = buf;
-	origin->file.size = fin_size;
-	pretend_sha1_file(buf, fin_size, OBJ_BLOB, origin->blob_sha1);
+	origin->file.ptr = buf.buf;
+	origin->file.size = buf.len;
+	pretend_sha1_file(buf.buf, buf.len, OBJ_BLOB, origin->blob_sha1);
 	commit->util = origin;
 
 	/*

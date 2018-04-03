 		error("cannot fork to run external filter %s", cmd);
 		close(pipe_feed[0]);
 		close(pipe_feed[1]);
-		return NULL;
+		return 0;
 	}
 	if (!child_process.pid) {
 		dup2(pipe_feed[1], 1);
 		close(pipe_feed[0]);
 		close(pipe_feed[1]);
-		exit(filter_buffer(path, src, *sizep, cmd));
+		exit(filter_buffer(path, src, len, cmd));
 	}
 	close(pipe_feed[1]);
 
-	dstalloc = *sizep;
-	dst = xmalloc(dstalloc);
-	dstsize = 0;
-
-	while (1) {
-		ssize_t numread = xread(pipe_feed[0], dst + dstsize,
-					dstalloc - dstsize);
-
-		if (numread <= 0) {
-			if (!numread)
-				break;
-			error("read from external filter %s failed", cmd);
-			free(dst);
-			dst = NULL;
-			break;
-		}
-		dstsize += numread;
-		if (dstalloc <= dstsize + SLOP) {
-			dstalloc = dstsize + SLOP;
-			dst = xrealloc(dst, dstalloc);
-		}
+	strbuf_init(&nbuf, 0);
+	if (strbuf_read(&nbuf, pipe_feed[0], len) < 0) {
+		error("read from external filter %s failed", cmd);
+		ret = 0;
 	}
 	if (close(pipe_feed[0])) {
-		error("read from external filter %s failed", cmd);
-		free(dst);
-		dst = NULL;
+		ret = error("read from external filter %s failed", cmd);
+		ret = 0;
 	}
-
 	status = finish_command(&child_process);
 	if (status) {
-		error("external filter %s failed %d", cmd, -status);
-		free(dst);
-		dst = NULL;
+		ret = error("external filter %s failed %d", cmd, -status);
+		ret = 0;
 	}
 
-	if (dst)
-		*sizep = dstsize;
-	return dst;
+	if (ret) {
+		*dst = nbuf;
+	} else {
+		strbuf_release(&nbuf);
+	}
+	return ret;
 }
 
 static struct convert_driver {

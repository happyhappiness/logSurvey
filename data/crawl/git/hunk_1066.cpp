 	}
 	strbuf_addstr(&pathbuf, entry);
 
-	normalize_path_copy(pathbuf.buf, pathbuf.buf);
+	if (strbuf_normalize_path(&pathbuf) < 0) {
+		error("unable to normalize alternate object path: %s",
+		      pathbuf.buf);
+		strbuf_release(&pathbuf);
+		return -1;
+	}
 
 	pfxlen = strlen(pathbuf.buf);
 

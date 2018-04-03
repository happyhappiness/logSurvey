 		strbuf_addstr(&pathbuf, filename);
 	}
 
-	name = strbuf_detach(&pathbuf, NULL);
-
 #ifndef NO_PTHREADS
 	if (use_threads) {
-		grep_sha1_async(opt, name, sha1);
+		add_work(GREP_SOURCE_SHA1, pathbuf.buf, sha1);
+		strbuf_release(&pathbuf);
 		return 0;
 	} else
 #endif
 	{
+		struct grep_source gs;
 		int hit;
-		unsigned long sz;
-		void *data = load_sha1(sha1, &sz, name);
-		if (!data)
-			hit = 0;
-		else
-			hit = grep_buffer(opt, name, data, sz);
 
-		free(data);
-		free(name);
-		return hit;
-	}
-}
+		grep_source_init(&gs, GREP_SOURCE_SHA1, pathbuf.buf, sha1);
+		strbuf_release(&pathbuf);
+		hit = grep_source(opt, &gs);
 
-static void *load_file(const char *filename, size_t *sz)
-{
-	struct stat st;
-	char *data;
-	int i;
-
-	if (lstat(filename, &st) < 0) {
-	err_ret:
-		if (errno != ENOENT)
-			error(_("'%s': %s"), filename, strerror(errno));
-		return NULL;
-	}
-	if (!S_ISREG(st.st_mode))
-		return NULL;
-	*sz = xsize_t(st.st_size);
-	i = open(filename, O_RDONLY);
-	if (i < 0)
-		goto err_ret;
-	data = xmalloc(*sz + 1);
-	if (st.st_size != read_in_full(i, data, *sz)) {
-		error(_("'%s': short read %s"), filename, strerror(errno));
-		close(i);
-		free(data);
-		return NULL;
+		grep_source_clear(&gs);
+		return hit;
 	}
-	close(i);
-	data[*sz] = 0;
-	return data;
 }
 
 static int grep_file(struct grep_opt *opt, const char *filename)
 {
 	struct strbuf buf = STRBUF_INIT;
-	char *name;
 
 	if (opt->relative && opt->prefix_length)
 		quote_path_relative(filename, -1, &buf, opt->prefix);
 	else
 		strbuf_addstr(&buf, filename);
-	name = strbuf_detach(&buf, NULL);
 
 #ifndef NO_PTHREADS
 	if (use_threads) {
-		grep_file_async(opt, name, filename);
+		add_work(GREP_SOURCE_FILE, buf.buf, filename);
+		strbuf_release(&buf);
 		return 0;
 	} else
 #endif
 	{
+		struct grep_source gs;
 		int hit;
-		size_t sz;
-		void *data = load_file(filename, &sz);
-		if (!data)
-			hit = 0;
-		else
-			hit = grep_buffer(opt, name, data, sz);
 
-		free(data);
-		free(name);
+		grep_source_init(&gs, GREP_SOURCE_FILE, buf.buf, filename);
+		strbuf_release(&buf);
+		hit = grep_source(opt, &gs);
+
+		grep_source_clear(&gs);
 		return hit;
 	}
 }
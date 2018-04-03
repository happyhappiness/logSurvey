 
 struct sha1file *sha1fd_throughput(int fd, const char *name, struct progress *tp)
 {
-	struct sha1file *f;
-	unsigned len;
-
-	f = xmalloc(sizeof(*f));
-
-	len = strlen(name);
-	if (len >= PATH_MAX)
-		die("you wascally wabbit, you");
-	f->namelen = len;
-	memcpy(f->name, name, len+1);
-
+	struct sha1file *f = xmalloc(sizeof(*f));
 	f->fd = fd;
-	f->error = 0;
 	f->offset = 0;
 	f->total = 0;
 	f->tp = tp;
+	f->name = name;
 	f->do_crc = 0;
 	SHA1_Init(&f->ctx);
 	return f;

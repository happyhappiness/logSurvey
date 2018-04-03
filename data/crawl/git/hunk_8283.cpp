 	return 0;
 }
 
-struct sha1file *sha1create(const char *fmt, ...)
-{
-	struct sha1file *f;
-	unsigned len;
-	va_list arg;
-	int fd;
-
-	f = xmalloc(sizeof(*f));
-
-	va_start(arg, fmt);
-	len = vsnprintf(f->name, sizeof(f->name), fmt, arg);
-	va_end(arg);
-	if (len >= PATH_MAX)
-		die("you wascally wabbit, you");
-	f->namelen = len;
-
-	fd = open(f->name, O_CREAT | O_EXCL | O_WRONLY, 0666);
-	if (fd < 0)
-		die("unable to open %s (%s)", f->name, strerror(errno));
-	f->fd = fd;
-	f->error = 0;
-	f->offset = 0;
-	f->do_crc = 0;
-	SHA1_Init(&f->ctx);
-	return f;
-}
-
 struct sha1file *sha1fd(int fd, const char *name)
 {
 	struct sha1file *f;

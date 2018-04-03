 static void logfileWriteWrapper(Logfile * lf, const void *buf, size_t len);
 
 Logfile *
-logfileOpen(const char *path, size_t bufsz)
+logfileOpen(const char *path, size_t bufsz, int fatal_flag)
 {
     int fd;
     Logfile *lf;
     fd = file_open(path, O_WRONLY | O_CREAT);
     if (DISK_ERROR == fd) {
-	if (ENOENT == errno) {
+	if (ENOENT == errno && fatal_flag) {
 	    fatalf("Cannot open '%s' because\n"
 		"\tthe parent directory does not exist.\n"
 		"\tPlease create the directory.\n", path);
-	} else if (EACCES == errno) {
+	} else if (EACCES == errno && fatal_flag) {
 	    fatalf("Cannot open '%s' for writing.\n"
 		"\tThe parent directory must be writeable by the\n"
 		"\tuser '%s', which is the cache_effective_user\n"

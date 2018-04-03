 /* squid convert handler */
 /* call for each line in file, use fileWalk routine */
 static int
-squidReadHandler(int fd_unused, char *buf, int size_unused, squid_read_data_t * data)
+squidReadHandler(int fd_unused, const char *buf, int size_unused, squid_read_data_t *data)
 {
     storeAppendPrintf(data->sentry, "{\"%s\"}\n", buf);
     return 0;

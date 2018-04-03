 
         if (conn != NULL) {
             const int fd = conn->clientConnection->fd;
-            storeAppendPrintf(s, "\tFD %d, read %"PRId64", wrote %"PRId64"\n", fd,
+            storeAppendPrintf(s, "\tFD %d, read %" PRId64 ", wrote %" PRId64 "\n", fd,
                               fd_table[fd].bytes_read, fd_table[fd].bytes_written);
             storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
             storeAppendPrintf(s, "\tin: buf %p, offset %ld, size %ld\n",

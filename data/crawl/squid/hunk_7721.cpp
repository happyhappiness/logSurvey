 	file_table[fd].write_daemon = NOT_PRESENT;
 	file_table[fd].filename[0] = '\0';
 
-	if (fdstat_type(fd) == Socket) {
+	if (fdstat_type(fd) == FD_SOCKET) {
 	    debug(6, 0, "FD %d: Someone called file_close() on a socket\n", fd);
 	    fatal_dump(NULL);
 	}

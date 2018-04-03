 	return -1;
 
     if (fdstat_type(fd) == File) {
-	debug(0, "FD %d: Someone called comm_close() on a File\n", fd);
+	debug(0, 0, "FD %d: Someone called comm_close() on a File\n", fd);
 	fatal_dump(NULL);
     }
     conn = &fd_table[fd];

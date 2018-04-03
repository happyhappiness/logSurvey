 
 	/* If input_fd is a file, we should have reached its end now. */
 	if (fstat(input_fd, &st))
-		die("cannot fstat packfile: %s", strerror(errno));
+		die_errno("cannot fstat packfile");
 	if (S_ISREG(st.st_mode) &&
 			lseek(input_fd, 0, SEEK_CUR) - input_len != st.st_size)
 		die("pack has junk at the end");

 		if (!len)
 			break;
 		if (len < 0) {
-			int read_error;
-			read_error = errno;
+			int read_error = errno;
 			close(ifd);
 			return error("copy-fd: read returned %s",
 				     strerror(read_error));

 	    if (FD[i].cb == NULL)
 		continue;
 	    if (now.tv_sec - FD[i].start > lifetime) {
+		fprintf(stderr, "WARNING: fd %d lifetime timeout\n", i);
 		fd_close(i);
 		continue;
 	    }
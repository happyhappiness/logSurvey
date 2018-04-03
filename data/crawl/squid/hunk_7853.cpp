 	sprintf(tmp_error_buf, "Cannot open swap logfile: %s", swaplog_file);
 	fatal(tmp_error_buf);
     }
-    swaplog_stream = fdopen(swaplog_fd, "w");
-    if (!swaplog_stream) {
-	sprintf(tmp_error_buf, "Cannot open a stream for swap logfile: %s",
-	    swaplog_file);
-	fatal(tmp_error_buf);
-    }
     swaplog_lock = file_write_lock(swaplog_fd);
 
     stop = getCurrentTime();

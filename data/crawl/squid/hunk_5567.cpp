     case STREAM_UNPLANNED_COMPLETE:
 	/* fallthrough */
     case STREAM_FAILED:
-	if (fd != -1)
-	    comm_close(fd);
+	comm_close(fd);
 	return;
     default:
 	fatal("Hit unreachable code in clientWriteComplete\n");

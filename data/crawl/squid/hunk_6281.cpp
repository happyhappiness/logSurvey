 	memFree(MEM_8K_BUF, redirector->inbuf);
 	redirector->inbuf = NULL;
 	comm_close(fd);
-	if (--NRedirectorsOpen == 0 && !shutting_down)
-	    fatal_dump("All redirectors have exited!");
 	return;
     }
     if (len != 1)

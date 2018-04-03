 	comm_close(fd);
 	if (--NRedirectorsOpen == 0 && !shutdown_pending && !reread_pending)
 	    fatal_dump("All redirectors have exited!");
-	return 0;
+	return;
     }
     if (len != 1)
 	RedirectStats.rewrites[redirector->index]++;

 		break;
 	    if (errno == EINTR)
 		continue;
-	    debug(5, 0, "comm_select: poll failure: %s\n",
-		xstrerror());
-	    if (errno == EINVAL) {
-		/* nfds greater than OPEN_MAX?? How possible? Time */
-		/* to bail - write out nfds to cache.log and start */
-		/* emergency shutdown by sending SIGTERM to self */
-		debug(20, 1, "Poll returned EINVAL. Polled %d FD's\n", nfds);
-		kill(getpid(), SIGTERM);
-	    }
+	    debug(5, 0, "comm_poll: poll failure: %s\n", xstrerror());
+	    if (errno == EINVAL) 
+		fatal_dump("Poll returned EINVAL");
 	    return COMM_ERROR;
 	    /* NOTREACHED */
 	}
 	getCurrentTime();
-	debug(5, num ? 5 : 8, "comm_select: %d sockets ready at %d\n",
-	    num, (int) squid_curtime);
+	debug(5, num ? 5 : 8, "comm_poll: %d sockets ready\n", num);
 	/* Check timeout handlers ONCE each second. */
 	if (squid_curtime > last_timeout) {
 	    last_timeout = squid_curtime;

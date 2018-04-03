     storeAppendPrintf(sentry, "{\tReserved number of file descriptors:  %4d}\n",
 	RESERVED_FD);
 
-    {
-	int i;
-	char *s = NULL;
-
-	storeAppendPrintf(sentry, "{\tActive file descriptors:}\n");
-
-	for (i = 0; i < FD_SETSIZE; i++) {
-	    int lft, to;
-	    if (!fdstat_isopen(i))
-		continue;
-	    line[0] = '\0';
-	    switch (fdstat_type(i)) {
-	    case FD_SOCKET:
-		/* the lifetime should be greater than curtime */
-		lft = comm_get_fd_lifetime(i);
-		to = comm_get_fd_timeout(i);
-		storeAppendPrintf(sentry, "{\t\t(%3d = %3d, %3d) NET %s}\n",
-		    i,
-		    (int) (lft > 0 ? lft - squid_curtime : -1),
-		    (int) max((to - squid_curtime), 0),
-		    fd_note(i, NULL));
-		break;
-	    case FD_FILE:
-		storeAppendPrintf(sentry, "{\t\t(%3d = FILE) %s}\n", i,
-		    (s = diskFileName(i)) ? s : "Unknown");
-		break;
-	    case FD_PIPE:
-		storeAppendPrintf(sentry, "{\t\t(%3d = PIPE) %s}\n", i, fd_note(i, NULL));
-		break;
-	    case FD_LOG:
-		storeAppendPrintf(sentry, "{\t\t(%3d = LOG) %s}\n", i, fd_note(i, NULL));
-		break;
-	    case FD_UNKNOWN:
-	    default:
-		storeAppendPrintf(sentry, "{\t\t(%3d = UNKNOWN) %s}\n", i, fd_note(i, NULL));
-		break;
-	    }
-	}
-    }
-
-
     storeAppendPrintf(sentry, "{Stop List:}\n");
     if ((p = getHttpStoplist())) {
 	storeAppendPrintf(sentry, "{\tHTTP:}\n");

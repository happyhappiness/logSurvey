 	    continue;
 	j = fdstatGetType(i);
 	storeAppendPrintf(sentry, "{%4d %-6s ",
-		i,
-		fdstatTypeStr[j]);
+	    i,
+	    fdstatTypeStr[j]);
 	switch (j) {
 	case FD_SOCKET:
 	    if ((lft = comm_get_fd_lifetime(i)) < 0)

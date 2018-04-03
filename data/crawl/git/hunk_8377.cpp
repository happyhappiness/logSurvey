 	if (flags & CONNECT_VERBOSE)
 		fprintf(stderr, "done.\nConnecting to %s (port %s) ... ", host, port);
 
-	for (ap = he->h_addr_list; *ap; ap++) {
+	for (cnt = 0, ap = he->h_addr_list; *ap; ap++, cnt++) {
 		sockfd = socket(he->h_addrtype, SOCK_STREAM, 0);
 		if (sockfd < 0) {
 			saved_errno = errno;

     if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
 	fatal_dump(xstrerror());
     if ((pid = fork()) < 0) {
-	debug(50, 0, "icmpOpen: fork: %s\n", xstrerror());
+	debug(50, 0) ("icmpOpen: fork: %s\n", xstrerror());
 	comm_close(icmp_sock);
 	comm_close(child_sock);
 	return;

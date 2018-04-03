     }
     getsockname(icmp_sock, (struct sockaddr *) &S, &namelen);
     if (comm_connect_addr(child_sock, &S) != COMM_OK)
-	fatal_dump(xstrerror());
+	fatal(xstrerror());
     getsockname(child_sock, (struct sockaddr *) &S, &namelen);
     if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
-	fatal_dump(xstrerror());
+	fatal(xstrerror());
     /* flush or else we get dup data if unbuffered_logs is set */
     logsFlush();
     if ((pid = fork()) < 0) {

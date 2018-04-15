  * Send a message over the network. The send consists of
  * two network packets. The first is sends a short containing
  * the length of the data packet which follows.
- * Returns zero on success
- * Returns non-zero on error
+ * Returns number of bytes sent
+ * Returns -1 on error
  */
 static int net_send(int sockfd, char *buff, int len)
 {
 	int rc;
-	short packet_size;
+	short pktsiz;
 
 	/* send short containing size of data packet */
-	packet_size = htons ((short) len);
-
-	rc = write_nbytes(sockfd, &packet_size, sizeof (packet_size));
-	if (rc != sizeof(packet_size))
-		return (-1);
+	pktsiz = htons((short)len);
+	rc = write_nbytes(sockfd, (char *)&pktsiz, sizeof(short));
+	if (rc != sizeof(short)) {
+		net_errmsg = "net_send: write_nbytes error of length prefix\n";
+		return -1;
+	}
 
 	/* send data packet */
-	rc = write_nbytes (sockfd, buff, len);
-	if (rc != len)
-		return (-1);
+	rc = write_nbytes(sockfd, buff, len);
+	if (rc != len) {
+		net_errmsg = "net_send: write_nbytes error\n";
+		return -1;
+	}
 
-	return (0);
+	return rc;
 }
 
+
 /* Get and print status from apcupsd NIS server */
 static int do_pthreads_status(char *host, int port, struct apc_detail_s *apcups_detail)
 {
+<<<<<<< .mine
+  int sockfd, n;
+  char recvline[MAXSTRING + 1];
+  char *tokptr;
+
+  if ((sockfd = net_open(host, NULL, port)) < 0){
+    syslog(LOG_ERR, "apcups: Cannot open connection: %s",
+	   net_errmsg);
+    net_errmsg = NULL;
+    return;
+  }
+  
+  net_send(sockfd, "status", 6);
+  
+  while ((n = net_recv(sockfd, recvline, sizeof(recvline))) > 0) {
+    recvline[n] = 0;
+#ifdef APCMAIN
+    fputs(recvline, stdout);
+#endif /* ifdef APCMAIN */
+=======
 	int     sockfd;
 	int     n;
 	char    recvline[MAXSTRING + 1];

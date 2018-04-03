      int fd;
 {
     int j;
-    struct sockaddr_in our_socket_name;
+    struct sockaddr_in name;
     struct sockaddr_in *ap;
-    int sock_name_length = sizeof(our_socket_name);
+    int len = sizeof(struct sockaddr_in);
     char **list = NULL;
     edge *e = NULL;
+    edge *next = NULL;
+    edge **E = NULL;
     struct in_addr *ina = NULL;
+    struct servent *sep = NULL;
 
-    if (getsockname(fd, (struct sockaddr *) &our_socket_name,
-	    &sock_name_length) == -1) {
-	debug(15, 1, "getsockname(%d,%p,%p) failed.\n",
-	    fd, &our_socket_name, &sock_name_length);
-    }
+    memset(&name, '\0', sizeof(struct sockaddr_in));
+    if (getsockname(fd, (struct sockaddr *) &name, &len) < 0)
+	debug(15, 1, "getsockname(%d,%p,%p) failed.\n", fd, &name, &len);
     friends->fd = fd;
 
     /* Prepare neighbor connections, one at a time */
-    for (e = friends->edges_head; e; e = e->next) {
+    E = &friends->edges_head;
+    next = friends->edges_head;
+    while ((e = next)) {
+	next = e->next;
 	debug(15, 2, "Finding IP addresses for '%s'\n", e->host);
 	if ((list = getAddressList(e->host)) == NULL) {
-	    sprintf(tmp_error_buf, "DNS lookup for '%s' failed! Cannot continue.\n",
-		e->host);
-	    fatal(tmp_error_buf);
+	    debug(0, 0, "WARNING!!: DNS lookup for '%s' failed!\n", e->host);
+	    debug(0, 0, "THIS NEIGHBOR WILL BE IGNORED.\n");
+	    *E = next;		/* skip */
+	    safe_free(e);
+	    continue;
 	}
+	ipcacheLockEntry(e->host);
 	e->n_addresses = 0;
 	for (j = 0; *list && j < EDGE_MAX_ADDRESSES; j++) {
 	    ina = &e->addresses[j];
-	    memcpy(&(ina->s_addr), *list, 4);
+	    xmemcpy(&(ina->s_addr), *list, 4);
 	    list++;
 	    e->n_addresses++;
 	}
 	if (e->n_addresses < 1) {
-	    sprintf(tmp_error_buf, "No IP addresses found for '%s'; Cannot continue.\n", e->host);
-	    fatal(tmp_error_buf);
+	    debug(0, 0, "WARNING!!: No IP address found for '%s'!\n", e->host);
+	    debug(0, 0, "THIS NEIGHBOR WILL BE IGNORED.\n");
+	    *E = next;		/* skip */
+	    safe_free(e);
+	    continue;
 	}
 	for (j = 0; j < e->n_addresses; j++) {
-	    debug(15, 2, "--> IP address #%d: %s\n", j, inet_ntoa(e->addresses[j]));
+	    debug(15, 2, "--> IP address #%d: %s\n",
+		j, inet_ntoa(e->addresses[j]));
 	}
-	e->rtt = 1000;
+	e->stats.rtt = 0;
 
 	/* Prepare query packet for future use */
 	e->header.opcode = ICP_OP_QUERY;
 	e->header.version = ICP_VERSION_CURRENT;
 	e->header.length = 0;
 	e->header.reqnum = 0;
-	memset(e->header.auth, '\0', sizeof(u_num32) * ICP_AUTH_SIZE);
-	e->header.shostid = our_socket_name.sin_addr.s_addr;
+	e->header.flags = 0;
+	e->header.pad = 0;
+	/* memset(e->header.auth, '\0', sizeof(u_num32) * ICP_AUTH_SIZE); */
+	e->header.shostid = name.sin_addr.s_addr;
 
 	ap = &e->in_addr;
 	memset(ap, '\0', sizeof(struct sockaddr_in));
 	ap->sin_family = AF_INET;
 	ap->sin_addr = e->addresses[0];
-	ap->sin_port = htons(e->udp_port);
+	ap->sin_port = htons(e->icp_port);
 
 	if (e->type == EDGE_PARENT) {
 	    debug(15, 3, "parent_install: host %s addr %s port %d\n",
 		e->host, inet_ntoa(ap->sin_addr),
-		e->udp_port);
+		e->icp_port);
 	    e->neighbor_up = 1;
 	} else {
 	    debug(15, 3, "neighbor_install: host %s addr %s port %d\n",
 		e->host, inet_ntoa(ap->sin_addr),
-		e->udp_port);
+		e->icp_port);
 	    e->neighbor_up = 1;
 	}
+	E = &e->next;
+    }
 
-	/* do this only the first time thru */
-	if (0 == echo_hdr.opcode) {
-	    struct servent *sep;
-
-	    echo_hdr.opcode = ICP_OP_SECHO;
-	    echo_hdr.version = ICP_VERSION_CURRENT;
-	    echo_hdr.length = 0;
-	    echo_hdr.reqnum = 0;
-	    memset(echo_hdr.auth, '\0', sizeof(u_num32) * ICP_AUTH_SIZE);
-	    echo_hdr.shostid = our_socket_name.sin_addr.s_addr;
-
-	    sep = getservbyname("echo", "udp");
-	    echo_port = sep ? ntohs((u_short) sep->s_port) : 7;
-	}
+    if (0 == echo_hdr.opcode) {
+	echo_hdr.opcode = ICP_OP_SECHO;
+	echo_hdr.version = ICP_VERSION_CURRENT;
+	echo_hdr.length = 0;
+	echo_hdr.reqnum = 0;
+	echo_hdr.flags = 0;
+	echo_hdr.pad = 0;
+	/* memset(echo_hdr.auth, '\0', sizeof(u_num32) * ICP_AUTH_SIZE); */
+	echo_hdr.shostid = name.sin_addr.s_addr;
+	sep = getservbyname("echo", "udp");
+	echo_port = sep ? ntohs((u_short) sep->s_port) : 7;
     }
 }
 

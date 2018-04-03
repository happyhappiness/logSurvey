      * For each request outstanding, add it's socket to the fdset,
      * and if it is the earliest timeout to expire, mark it as lowest.
      */
-    for (slp = Sessions; slp; slp = slp->next) {
+    for(slp = Sessions; slp; slp = slp->next){
+
 	active++;
 	isp = slp->internal;
 	if ((isp->sd + 1) > *numfds)
 	    *numfds = (isp->sd + 1);
 	FD_SET(isp->sd, fdset);
-	if (isp->requests) {
+      snmplib_debug(6,"LIBSNMP:  select():  Adding port %d\n", isp->sd);
+	if (isp->requests){
 	    /* found another session with outstanding requests */
 	    requests++;
-	    for (rp = isp->requests; rp; rp = rp->next_request) {
-		if (!timerisset(&earliest) || timercmp(&rp->expire, &earliest, <))
+	    for(rp = isp->requests; rp; rp = rp->next_request){
+		if (!timerisset(&earliest) || 
+		    timercmp(&rp->expire, &earliest, <))
 		    earliest = rp->expire;
 	    }
 	}
     }
-    if (requests == 0)		/* if none are active, skip arithmetic */
+      snmplib_debug(6,"LIBSNMP:  Select Info:  %d active, %d requests pending.\n",
+	     active, requests);
+
+    if (requests == 0)	/* if none are active, skip arithmetic */
 	return active;
 
     /*
      * Now find out how much time until the earliest timeout.  This
      * transforms earliest from an absolute time into a delta time, the
      * time left until the select should timeout.
      */
-    gettimeofday(&now, (struct timezone *) 0);
-    earliest.tv_sec--;		/* adjust time to make arithmetic easier */
+    gettimeofday(&now, (struct timezone *)0);
+    earliest.tv_sec--;	/* adjust time to make arithmetic easier */
     earliest.tv_usec += 1000000L;
     earliest.tv_sec -= now.tv_sec;
     earliest.tv_usec -= now.tv_usec;
-    while (earliest.tv_usec >= 1000000L) {
+    while (earliest.tv_usec >= 1000000L){
 	earliest.tv_usec -= 1000000L;
 	earliest.tv_sec += 1;
     }
-    if (earliest.tv_sec < 0) {
+    if (earliest.tv_sec < 0){
 	earliest.tv_sec = 0;
 	earliest.tv_usec = 0;
     }
+
     /* if it was blocking before or our delta time is less, reset timeout */
-    if (*block == 1 || timercmp(&earliest, timeout, <)) {
+    if (*block == 1 || timercmp(&earliest, timeout, <)){
 	*timeout = earliest;
 	*block = 0;
     }
     return active;
 }
 
-/* 
- * snmp_timeout should be called whenever the timeout from
- * snmp_select_info expires, but it is idempotent, so snmp_timeout can
- * be polled (probably a cpu expensive proposition).  snmp_timeout
- * checks to see if any of the sessions have an outstanding request
- * that has timed out.  If it finds one (or more), and that pdu has
- * more retries available, a new packet is formed from the pdu and is
- * resent.  If there are no more retries available, the callback for
- * the session is used to alert the user of the timeout.
+/*
+ * snmp_timeout should be called whenever the timeout from snmp_select_info 
+ * expires, but it is idempotent, so snmp_timeout can be polled (probably a 
+ * cpu expensive proposition).  snmp_timeout checks to see if any of the 
+ * sessions have an outstanding request that has timed out.  If it finds one 
+ * (or more), and that pdu has more retries available, a new packet is formed
+ * from the pdu and is resent.  If there are no more retries available, the 
+ * callback for the session is used to alert the user of the timeout.
  */
-void
-snmp_timeout(void)
+void snmp_timeout(void)
 {
-    struct session_list *slp;
-    struct snmp_session *sp;
-    struct snmp_internal_session *isp;
-    struct request_list *rp, *rp_next = 0;
-    struct timeval now;
-
-    gettimeofday(&now, (struct timezone *) 0);
-    /*
-     * For each request outstanding, check to see if it has expired.
-     */
-    for (slp = Sessions; slp; slp = slp->next) {
-	sp = slp->session;
-	isp = slp->internal;
-	for (rp = isp->requests; rp; rp = rp_next) {
-	    rp_next = rp->next_request;
-	    if (timercmp(&rp->expire, &now, <)) {
-		/* this timer has expired */
-		if (rp->retries >= sp->retries) {
-#if DEBUG_SNMPTRACE
-		    snmp_print_trace(slp, rp, TRACE_TIMEOUT);
-#endif
-		    /* No more chances, delete this entry */
-		    sp->callback(TIMED_OUT, sp, rp->pdu->reqid, rp->pdu, sp->callback_magic);
-		    free_one_request(isp, rp);
-		    continue;
-		} else {
-		    u_char packet[PACKET_LENGTH];
+  struct session_list *slp;
+  struct snmp_session *sp;
+  struct snmp_internal_session *isp;
+  struct request_list *rp, *orp, *freeme = NULL;
+  struct timeval now;
+
+  gettimeofday(&now, (struct timezone *)0);
+
+  /*
+   * For each request outstanding, check to see if it has expired.
+   */
+  for(slp = Sessions; slp; slp = slp->next) {
+    sp = slp->session;
+    isp = slp->internal;
+    orp = NULL;
+snmplib_debug(6,"LIBSNMP:  Checking session %s\n", 
+       (sp->peername != NULL) ? sp->peername : "<NULL>");
+    for(rp = isp->requests; rp; rp = rp->next_request) {
+snmplib_debug(6,"LIBSNMP:  Checking session request %d, expire at %u, Retry %d/%d\n", 
+       rp->request_id, rp->expire.tv_sec, rp->retries, sp->retries);
+
+      if (freeme != NULL) {
+	/* frees rp's after the for loop goes on to the next_request */
+	xfree((char *)freeme);
+	freeme = NULL;
+      }
+
+      if (timercmp(&rp->expire, &now, <)) {
+
+snmplib_debug(6,"LIBSNMP:  Expired.\n");
+
+	/* this timer has expired */
+	if (rp->retries >= sp->retries) {
+	  /* No more chances, delete this entry */
+	  sp->callback(TIMED_OUT, sp, rp->pdu->reqid, 
+		       rp->pdu, sp->callback_magic);
+	  if (orp == NULL) {
+	    isp->requests = rp->next_request;
+	  } else {
+	    orp->next_request = rp->next_request;
+	  }
+	  snmp_free_pdu(rp->pdu);
+	  freeme = rp;
+	  continue;	/* don't update orp below */
+	} else {
+		    u_char  packet[PACKET_LENGTH];
 		    int length = PACKET_LENGTH;
 		    struct timeval tv;
 
+snmplib_debug(6,"LIBSNMP:  Retransmitting.\n");
 		    /* retransmit this pdu */
 		    rp->retries++;
 		    rp->timeout <<= 1;
-		    if (snmp_build(sp, rp->pdu, packet, &length, 0) < 0) {
-#if NO_PRINTFS
-			fprintf(stderr, "Error building packet\n");
-#endif
+		    if (snmp_build(sp, rp->pdu, packet, &length) < 0){
+		      snmplib_debug(3, "Error building packet\n");
 		    }
-		    if (snmp_dump_packet) {
-			snmp_print_packet((char *)packet, length, rp->pdu->address, 1);
-		    }
-		    gettimeofday(&tv, (struct timezone *) 0);
-		    if (sendto(isp->sd, (char *) packet, length, 0, (struct sockaddr *) &rp->pdu->address, sizeof(rp->pdu->address)) < 0) {
+
+		    snmp_dump(packet, length, 
+			      "sending", rp->pdu->address.sin_addr);
+
+		    gettimeofday(&tv, (struct timezone *)0);
+		    if (sendto(isp->sd, (char *)packet, length, 0, (struct sockaddr *)&rp->pdu->address, sizeof(rp->pdu->address)) < 0){
 			perror("sendto");
 		    }
 		    rp->time = tv;
 		    tv.tv_usec += rp->timeout;
 		    tv.tv_sec += tv.tv_usec / 1000000L;
 		    tv.tv_usec %= 1000000L;
 		    rp->expire = tv;
-#if DEBUG_SNMPTRACE
-		    snmp_print_trace(slp, rp, TRACE_SEND);
-#endif
 		}
 	    }
+	    orp = rp;
+	}
+	if (freeme != NULL){
+	    xfree((char *)freeme);
+	    freeme = NULL;
+	}
+    }
+}
+
+
+/* Print some API stats */
+void snmp_api_stats(void *outP)
+{
+  struct session_list *slp;
+  struct request_list *rp;
+  struct snmp_internal_session *isp;
+  FILE *out = (FILE *)outP;
+
+  int active = 0;
+  int requests = 0;
+  int count = 0;
+  int rcount = 0;
+
+  fprintf(out, "LIBSNMP: Session List Dump\n");
+  fprintf(out, "LIBSNMP: ----------------------------------------\n");
+  for(slp = Sessions; slp; slp = slp->next){
+
+    isp = slp->internal;
+    active++;
+    count++;
+    fprintf(out, "LIBSNMP: %2d: Host %s\n", count, 
+	    (slp->session->peername == NULL) ? "NULL" : slp->session->peername);
+
+    if (isp->requests) {
+      /* found another session with outstanding requests */
+      requests++;
+      rcount=0;
+      for (rp=isp->requests; rp; rp=rp->next_request) {
+	rcount++;
+	{
+	  struct hostent *hp;
+	  hp = gethostbyaddr((char *)&(rp->pdu->address), 
+			     sizeof(u_int), AF_INET);
+	  fprintf(out, "LIBSNMP: %2d: ReqId %d (%s) (%s)\n", 
+		  rcount, rp->request_id, snmp_pdu_type(rp->pdu),
+		  (hp == NULL) ? "NULL" : hp->h_name);
 	}
+      }
     }
+    fprintf(out, "LIBSNMP: ----------------------------------------\n");
+  }
+  fprintf(out, "LIBSNMP: Session List: %d active, %d have requests pending.\n",
+	  active, requests);
 }

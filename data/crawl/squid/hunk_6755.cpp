  * On any error, 0 is returned.
  * The pdu is freed by snmp_send() unless a failure occured.
  */
-int
-snmp_send(struct snmp_session *session, struct snmp_pdu *pdu)
+int snmp_send(struct snmp_session *session, struct snmp_pdu *pdu)
 {
     struct session_list *slp;
     struct snmp_internal_session *isp = NULL;
-    u_char packet[PACKET_LENGTH];
+    u_char  packet[PACKET_LENGTH];
     int length = PACKET_LENGTH;
     struct request_list *rp;
     struct timeval tv;
 
-    for (slp = Sessions; slp; slp = slp->next) {
-	if (slp->session == session) {
+  if (Reqid == 0)
+    init_snmp();
+
+    for(slp = Sessions; slp; slp = slp->next){
+	if (slp->session == session){
 	    isp = slp->internal;
 	    break;
 	}
     }
-
-    if (!pdu) {
-	snmp_errno = SNMPERR_GENERR;
-	return 0;
-    }
-    if (isp == NULL) {
+    if (isp == NULL){
 	snmp_errno = SNMPERR_BAD_SESSION;
 	return 0;
     }
-    if (pdu->command == GET_REQ_MSG || pdu->command == GETNEXT_REQ_MSG
-	|| pdu->command == GET_RSP_MSG || pdu->command == SET_REQ_MSG
-	|| pdu->command == GETBULK_REQ_MSG) {
-	if (pdu->reqid == SNMP_DEFAULT_REQID)
-	    pdu->reqid = ++Reqid;
-	if (pdu->errstat == SNMP_DEFAULT_ERRSTAT)
-	    pdu->errstat = 0;
-	if (pdu->errindex == SNMP_DEFAULT_ERRINDEX)
-	    pdu->errindex = 0;
+
+    if (pdu->command == SNMP_PDU_GET || 
+	pdu->command == SNMP_PDU_GETNEXT ||
+	pdu->command == SNMP_PDU_RESPONSE || 
+	pdu->command == SNMP_PDU_SET) {
+
+      if (pdu->reqid == SNMP_DEFAULT_REQID)
+	pdu->reqid = ++Reqid;
+      if (pdu->errstat == SNMP_DEFAULT_ERRSTAT)
+	pdu->errstat = 0;
+      if (pdu->errindex == SNMP_DEFAULT_ERRINDEX)
+	pdu->errindex = 0;
+
+    } else if (pdu->command == SNMP_PDU_INFORM || 
+	       pdu->command == SNMP_PDU_GETBULK ||
+	       pdu->command == SNMP_PDU_V2TRAP) {
+
+      if (session->Version != SNMP_VERSION_2){
+	snmplib_debug(3, "Cant send SNMPv2 PDU's in SNMP message.\n");
+	snmp_errno = SNMPERR_GENERR;/* Fix this XXXXX */
+	return 0;
+      }
+      if (pdu->reqid == SNMP_DEFAULT_REQID)
+	pdu->reqid = ++Reqid;
+      if (pdu->errstat == SNMP_DEFAULT_ERRSTAT)
+	pdu->errstat = 0;
+      if (pdu->errindex == SNMP_DEFAULT_ERRINDEX)
+	pdu->errindex = 0;
+
     } else {
 	/* fill in trap defaults */
-	pdu->reqid = 1;		/* give a bogus non-error reqid for traps */
-	if (pdu->enterprise_length == SNMP_DEFAULT_ENTERPRISE_LENGTH) {
-	    pdu->enterprise = xcalloc(1, sizeof(DEFAULT_ENTERPRISE));
-	    xmemcpy(pdu->enterprise, DEFAULT_ENTERPRISE, sizeof(DEFAULT_ENTERPRISE));
-	    pdu->enterprise_length = sizeof(DEFAULT_ENTERPRISE) / sizeof(oid);
-	}
-	if (pdu->time == SNMP_DEFAULT_TIME)
-	    pdu->time = DEFAULT_TIME;
+      pdu->reqid = 1;	/* give a bogus non-error reqid for traps */
+      if (pdu->enterprise_length == SNMP_DEFAULT_ENTERPRISE_LENGTH) {
+	pdu->enterprise = (oid *)xmalloc(sizeof(DEFAULT_ENTERPRISE));
+	xmemcpy((char *)pdu->enterprise, (char *)DEFAULT_ENTERPRISE, 
+	       sizeof(DEFAULT_ENTERPRISE));
+	pdu->enterprise_length = sizeof(DEFAULT_ENTERPRISE)/sizeof(oid);
+      }
+      if (pdu->time == SNMP_DEFAULT_TIME)
+	pdu->time = DEFAULT_TIME;
     }
+
     if (pdu->address.sin_addr.s_addr == SNMP_DEFAULT_ADDRESS) {
-	if (isp->addr.sin_addr.s_addr != SNMP_DEFAULT_ADDRESS) {
-	    xmemcpy(&pdu->address, &isp->addr, sizeof(pdu->address));
-	} else {
-#if NO_PRINTFS
-	    fprintf(stderr, "No remote IP address specified\n");
-#endif
-	    snmp_errno = SNMPERR_BAD_ADDRESS;
-	    return 0;
-	}
-    }
-    if (snmp_build(session, pdu, packet, &length, 0) < 0) {
-#if NO_PRINTFS
-	fprintf(stderr, "Error building packet\n");
-#endif
-	snmp_errno = SNMPERR_GENERR;
+      if (isp->addr.sin_addr.s_addr != SNMP_DEFAULT_ADDRESS) {
+	xmemcpy((char *)&pdu->address, (char *)&isp->addr, 		 
+	       sizeof(pdu->address));
+      } else {
+	snmplib_debug(3, "No remote IP address specified\n");
+	snmp_errno = SNMPERR_BAD_ADDRESS;
 	return 0;
+      }
     }
-    if (snmp_dump_packet) {
-	snmp_print_packet((char *)packet, length, pdu->address, 1);
+	
+    if (snmp_build(session, pdu, packet, &length) < 0) {
+      snmplib_debug(3, "Error building packet\n");
+      snmp_errno = SNMPERR_GENERR;
+      return 0;
     }
-    gettimeofday(&tv, (struct timezone *) 0);
-    if (sendto(isp->sd, (char *) packet, length, 0, (struct sockaddr *) &pdu->address, sizeof(pdu->address)) < 0) {
-	perror("sendto");
-	snmp_errno = SNMPERR_GENERR;
-	return 0;
-    }
-    if (pdu->command == GET_REQ_MSG || pdu->command == GETNEXT_REQ_MSG
-	|| pdu->command == SET_REQ_MSG || pdu->command == GETBULK_REQ_MSG) {
-	/* set up to expect a response */
-	rp = xcalloc(1, sizeof(struct request_list));
-
-#if NOT_NEEDED
-	if (!rp) {
-	    fprintf(stderr, "Out of memory!\n");
-	    snmp_errno = SNMPERR_GENERR;
-	    return 0;
-	}
-#endif
-	rp->next_request = isp->requests;
-	isp->requests = rp;
-	rp->pdu = pdu;
-	rp->request_id = pdu->reqid;
-
-	rp->retries = 1;
-	rp->timeout = session->timeout;
-	rp->time = tv;
-	tv.tv_usec += rp->timeout;
-	tv.tv_sec += tv.tv_usec / 1000000L;
-	tv.tv_usec %= 1000000L;
-	rp->expire = tv;
-#if DEBUG_SNMPTRACE
-	snmp_print_trace(slp, rp, TRACE_SEND);
-#endif
+
+    snmp_dump(packet, length, "sending", pdu->address.sin_addr);
+
+    gettimeofday(&tv, (struct timezone *)0);
+    if (sendto(isp->sd, (char *)packet, length, 0, 
+	       (struct sockaddr *)&pdu->address, sizeof(pdu->address)) < 0){
+      perror("sendto");
+      snmp_errno = SNMPERR_GENERR;
+      return 0;
     }
-    return pdu->reqid;
-}
 
-/*
- * Frees the pdu and any malloc'd data associated with it.
- */
-void
-snmp_free_pdu(struct snmp_pdu *pdu)
-{
-    struct variable_list *vp, *ovp;
+    snmplib_debug(6,"LIBSNMP:  Sent PDU %s, Reqid %d\n", 
+	   snmp_pdu_type(pdu), pdu->reqid);
 
-    if (!pdu)
-	return;
+    if (pdu->command == SNMP_PDU_GET || 
+	pdu->command == SNMP_PDU_GETNEXT ||
+	pdu->command == SNMP_PDU_SET || 
+	pdu->command == SNMP_PDU_GETBULK ||
+	pdu->command == SNMP_PDU_INFORM) {
 
-    vp = pdu->variables;
-    while (vp) {
-	if (vp->name) {
-	    xfree((char *) vp->name);
-	}
-	if (vp->val.string) {
-	    xfree((char *) vp->val.string);
-	}
-	ovp = vp;
-	vp = vp->next_variable;
-	xfree((char *) ovp);
-    }
-    if (pdu->enterprise) {
-	xfree((char *) pdu->enterprise);
+snmplib_debug(6,"LIBSNMP:  Setting up to recieve a response for reqid %d\n", 
+       pdu->reqid);
+
+      /* set up to expect a response */
+      rp = (struct request_list *)xmalloc(sizeof(struct request_list));
+      rp->next_request = isp->requests;
+      isp->requests = rp;
+
+      rp->pdu = pdu;
+      rp->request_id = pdu->reqid;
+      
+      rp->retries = 1;
+      rp->timeout = session->timeout;
+      rp->time = tv;
+      tv.tv_usec += rp->timeout;
+      tv.tv_sec += tv.tv_usec / 1000000L;
+      tv.tv_usec %= 1000000L;
+      rp->expire = tv;
     }
-    xfree((char *) pdu);
-}
 
+    return(pdu->reqid);
+}
 
 /*
  * Checks to see if any of the fd's set in the fdset belong to

  * routine returns successfully, the pdu and it's request are deleted.
  */
 void
-snmp_read(fd_set * fdset)
+snmp_read(fdset)
+    fd_set  *fdset;
 {
     struct session_list *slp;
     struct snmp_session *sp;
     struct snmp_internal_session *isp;
     u_char packet[PACKET_LENGTH];
-    struct sockaddr_in from;
-    ssize_t length;
-    int fromlength;
+    struct sockaddr_in	from;
+    int length, fromlength;
     struct snmp_pdu *pdu;
-    struct request_list *rp /**, *orp **/ ;
+    struct request_list *rp, *orp;
+    u_char *bufp;
 
-    for (slp = Sessions; slp; slp = slp->next) {
-	if (FD_ISSET(slp->internal->sd, fdset)) {
-	    sp = slp->session;
-	    isp = slp->internal;
-	    fromlength = sizeof(from);
-	    length = recvfrom(isp->sd,
-		(char *) packet,
-		PACKET_LENGTH,
-		0,
-		(struct sockaddr *) &from,
-		&fromlength);
-	    if (length == -1) {
-		perror("recvfrom");
-		return;
-	    }
-	    if (snmp_dump_packet) {
-		snmp_print_packet((char *)packet, length, from, 0);
-	    }
-	    pdu = xcalloc(1, sizeof(struct snmp_pdu));
-#if NOT_NEEDED
-	    if (!pdu) {
-		fprintf(stderr, "Out of memory!\n");
-		snmp_errno = SNMPERR_GENERR;
-		return;
-	    }
-#endif
-	    pdu->address = from;
-	    pdu->reqid = 0;
-	    pdu->variables = NULL;
-	    pdu->enterprise = NULL;
-	    pdu->enterprise_length = 0;
-	    if (snmp_parse(sp, pdu, packet, length) < 0) {
-#if NO_PRINTFS
-		fprintf(stderr, "Mangled packet\n");
-#endif
-		snmp_free_pdu(pdu);
-		return;
-	    }
-	    if (pdu->command == GET_RSP_MSG || pdu->command == REPORT_MSG) {
-
-		struct request_list *rp_next = 0;
-		for (rp = isp->requests; rp; rp = rp_next) {
-		    rp_next = rp->next_request;
-		    if (rp->request_id == pdu->reqid) {
-#if DEBUG_SNMPTRACE
-			snmp_print_trace(slp, rp, TRACE_RECV);
-#endif
-			if (sp->callback(RECEIVED_MESSAGE, sp, pdu->reqid, pdu, sp->callback_magic) == 1) {
-			    /* successful, so delete request */
-			    free_one_request(isp, rp);
-			    break;	/* no more request with the same reqid */
-			}
+    for(slp = Sessions; slp; slp = slp->next) {
+      if (FD_ISSET(slp->internal->sd, fdset)) {
+	sp = slp->session;
+	isp = slp->internal;
+	fromlength = sizeof from;
+	length = recvfrom(isp->sd, (char *)packet, 
+			  PACKET_LENGTH, 0, (struct sockaddr *)&from, 
+			  &fromlength);
+	if (length == -1)
+	  perror("recvfrom");
+
+	snmp_dump(packet, length, "received", from.sin_addr);
+
+	pdu = snmp_pdu_create(0);
+	pdu->address = from;
+	pdu->reqid = 0;
+
+	/* Parse the incoming packet */
+	bufp = snmp_parse(sp, pdu, packet, length);
+	if (bufp == NULL) {
+	  snmplib_debug(3, "Mangled packet\n");
+	  snmp_free_pdu(pdu);
+	  return;
+	}
+	if (sp->community)
+	  xfree(sp->community);
+	sp->community = bufp;
+	sp->community_len = strlen((char *)bufp);
+
+snmplib_debug(6,"LIBSNMP:  Read PDU %s, ReqId %d\n", snmp_pdu_type(pdu), pdu->reqid);
+
+	if (pdu->command == SNMP_PDU_RESPONSE) {
+	  for(rp = isp->requests; rp; rp = rp->next_request) {
+	    if (rp->request_id == pdu->reqid) {
+snmplib_debug(6,"LIBSNMP:  ReqId %d:  Calling callback\n", pdu->reqid);
+	      if (sp->callback(RECEIVED_MESSAGE, sp, 
+			       pdu->reqid, pdu, 
+			       sp->callback_magic) == 1) {
+		/* successful, so delete request */
+snmplib_debug(6,"LIBSNMP:  ReqId %d:  Success.  Removing ReqId.\n", pdu->reqid);
+		orp = rp;
+		if (isp->requests == orp){
+		  /* first in list */
+		  isp->requests = orp->next_request;
+		} else {
+		  for(rp = isp->requests; rp; rp = rp->next_request){
+		    if (rp->next_request == orp){
+		      /* link around it */
+		      rp->next_request = orp->next_request;	
+		      break;
 		    }
+		  }
 		}
-	    } else if (pdu->command == GET_REQ_MSG
-		    || pdu->command == GETNEXT_REQ_MSG
-		    || pdu->command == GETBULK_REQ_MSG
-		|| pdu->command == TRP_REQ_MSG || pdu->command == SET_REQ_MSG) {
-#if DEBUG_SNMPTRACE
-		snmp_print_trace(slp, NULL, TRACE_RECV);
-#endif
-		sp->callback(RECEIVED_MESSAGE, sp, pdu->reqid, pdu, sp->callback_magic);
+		snmp_free_pdu(orp->pdu);
+		xfree((char *)orp);
+		/* there shouldn't be another req with the same reqid */
+		break;  
+	      }
 	    }
-	    snmp_free_pdu(pdu);
+	  }
+	} else if (pdu->command == SNMP_PDU_GET || 
+		   pdu->command == SNMP_PDU_GETNEXT ||
+		   pdu->command == TRP_REQ_MSG || 
+		   pdu->command == SNMP_PDU_SET ||
+		   pdu->command == SNMP_PDU_GETBULK ||
+		   pdu->command == SNMP_PDU_INFORM ||
+		   pdu->command == SNMP_PDU_V2TRAP) {
+	  sp->callback(RECEIVED_MESSAGE, sp, pdu->reqid, 
+		       pdu, sp->callback_magic);
 	}
+	snmp_free_pdu(pdu);
+      }
     }
 }
 

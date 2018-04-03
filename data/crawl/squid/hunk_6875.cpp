 	pdu->reqid = 1;		/* give a bogus non-error reqid for traps */
 	if (pdu->enterprise_length == SNMP_DEFAULT_ENTERPRISE_LENGTH) {
 	    pdu->enterprise = xcalloc(1, sizeof(DEFAULT_ENTERPRISE));
-	    bcopy((char *) DEFAULT_ENTERPRISE, (char *) pdu->enterprise, sizeof(DEFAULT_ENTERPRISE));
+	    xmemcpy(pdu->enterprise, DEFAULT_ENTERPRISE, sizeof(DEFAULT_ENTERPRISE));
 	    pdu->enterprise_length = sizeof(DEFAULT_ENTERPRISE) / sizeof(oid);
 	}
 	if (pdu->time == SNMP_DEFAULT_TIME)
 	    pdu->time = DEFAULT_TIME;
     }
     if (pdu->address.sin_addr.s_addr == SNMP_DEFAULT_ADDRESS) {
 	if (isp->addr.sin_addr.s_addr != SNMP_DEFAULT_ADDRESS) {
-	    bcopy((char *) &isp->addr, (char *) &pdu->address, sizeof(pdu->address));
+	    xmemcpy(&pdu->address, &isp->addr, sizeof(pdu->address));
 	} else {
 #if NO_PRINTFS
 	    fprintf(stderr, "No remote IP address specified\n");

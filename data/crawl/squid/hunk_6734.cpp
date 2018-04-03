 
 #include "mib.h"
 
-enum { HTTP_SVC, ICP_SVC, DNS_SVC };
+enum {
+    HTTP_SVC, ICP_SVC, DNS_SVC
+};
 
 static struct snmp_pdu *snmp_agent_response(struct snmp_pdu *PDU);
 struct snmp_session *Session;
 extern StatCounters *CountHist;
-extern int get_median_svc(int,int);
+extern int get_median_svc(int, int);
 
 /* returns: 
-	2: no such object in this mib
-        1: ok
-	0: failed */
+ * 2: no such object in this mib
+ * 1: ok
+ * 0: failed */
 
-int snmp_agent_parse(u_char *buf, int len, u_char *outbuf, int *outlen,
-        u_long from_addr, long * this_reqid)
+int
+snmp_agent_parse(u_char * buf, int len, u_char * outbuf, int *outlen,
+    u_long from_addr, long *this_reqid)
 {
-   struct snmp_pdu *PDU, *RespPDU;
-   u_char *Community;
-   int ret;
-   /* Now that we have the data, turn it into a PDU */
-   PDU = snmp_pdu_create(0);
-   Community = snmp_parse(Session, PDU, buf, len);
-   if (Community == NULL) {
-     debug(49,8)("snmp_agent_parse: Community == NULL\n");
-
-     snmp_free_pdu(PDU);
-     return 0;
-   }
+    struct snmp_pdu *PDU, *RespPDU;
+    u_char *Community;
+    int ret;
+    /* Now that we have the data, turn it into a PDU */
+    PDU = snmp_pdu_create(0);
+    Community = snmp_parse(Session, PDU, buf, len);
+    if (Community == NULL) {
+	debug(49, 8) ("snmp_agent_parse: Community == NULL\n");
+
+	snmp_free_pdu(PDU);
+	return 0;
+    }
 #if 0
-  if (!community_check(Community)) {
-    xfree(Community);
-    /* Wrong community! XXXXX */
-  }
+    if (!community_check(Community)) {
+	xfree(Community);
+	/* Wrong community! XXXXX */
+    }
 #endif
 
-  xfree(Community);
-  debug(49,5)("snmp_agent_parse: reqid=%d\n",PDU->reqid);
-  RespPDU = snmp_agent_response(PDU);
-  snmp_free_pdu(PDU);
-  if (RespPDU == NULL) {
-     debug(49,8)("snmp_agent_parse: RespPDU == NULL\n");
-    return 2;
-  }
-  debug(49,8)("snmp_agent_parse: Response pdu (%x) errstat=%d reqid=%d.\n", 
-		RespPDU,RespPDU->errstat,RespPDU->reqid);
+    xfree(Community);
+    debug(49, 5) ("snmp_agent_parse: reqid=%d\n", PDU->reqid);
+    RespPDU = snmp_agent_response(PDU);
+    snmp_free_pdu(PDU);
+    if (RespPDU == NULL) {
+	debug(49, 8) ("snmp_agent_parse: RespPDU == NULL\n");
+	return 2;
+    }
+    debug(49, 8) ("snmp_agent_parse: Response pdu (%x) errstat=%d reqid=%d.\n",
+	RespPDU, RespPDU->errstat, RespPDU->reqid);
 #if 0
-  if (RespPDU->variables) {
-	debug(49,8)("snmp_agent_parse: len=%d\n", RespPDU->variables->val_len);
-  }
+    if (RespPDU->variables) {
+	debug(49, 8) ("snmp_agent_parse: len=%d\n", RespPDU->variables->val_len);
+    }
 #endif
-  /* Encode it */
-  ret = snmp_build(Session, RespPDU, outbuf, outlen);
-  /* XXXXX Handle failure */
-  snmp_free_pdu(RespPDU);
-  return 1;
+    /* Encode it */
+    ret = snmp_build(Session, RespPDU, outbuf, outlen);
+    /* XXXXX Handle failure */
+    snmp_free_pdu(RespPDU);
+    return 1;
 }
 
 
 
-static struct snmp_pdu *snmp_agent_response(struct snmp_pdu *PDU)
+static struct snmp_pdu *
+snmp_agent_response(struct snmp_pdu *PDU)
 {
-  struct snmp_pdu *Answer = NULL;
-  variable_list *VarPtr, *VarNew = NULL;
-  variable_list **VarPtrP, **RespVars;
-  int index = 0;
-  oid_ParseFn *ParseFn;
-
-#ifdef DEBUG_SNMP
-  printf("Received a %d PDU\n", PDU->command);
-#endif
-
-  /* Create a response */
-  Answer = snmp_pdu_create(SNMP_PDU_RESPONSE);
-  if (Answer == NULL)
-    return(NULL);
-  Answer->reqid = PDU->reqid;
-  Answer->errindex = 0;
-
-  if (PDU->command == SNMP_PDU_GET) {
-
-    RespVars = &(Answer->variables);
-    /* Loop through all variables */
-    for (VarPtrP = &(PDU->variables); 
-       *VarPtrP; 
-       VarPtrP = &((*VarPtrP)->next_variable)) {
-      VarPtr = *VarPtrP;
-
-      index++;
-
-      /* Find the parsing function for this variable */
-      ParseFn = oidlist_Find(VarPtr->name, VarPtr->name_length);
-
-      if (ParseFn == NULL) {
-      Answer->errstat = SNMP_ERR_NOSUCHNAME;
-      debug(49,5)("snmp_agent_response: No such oid. ");
-      } else
-      VarNew = (*ParseFn)(VarPtr, (long *)&(Answer->errstat));
-
-      /* Was there an error? */
-      if ((Answer->errstat != SNMP_ERR_NOERROR) ||
-        (VarNew == NULL)) {
-      Answer->errindex = index;
-	debug(49,5)("snmp_agent_parse: successful.\n");
-      /* Just copy the rest of the variables.  Quickly. */
-      *RespVars = VarPtr;
-      *VarPtrP = NULL;
-      return(Answer);
-      }
-
-      /* No error.  Insert this var at the end, and move on to the next.
-       */
-      *RespVars = VarNew;
-      RespVars = &(VarNew->next_variable);
-    }
-
-    return(Answer);
-  }
-
-  else if (PDU->command == SNMP_PDU_GETNEXT) {
-    oid *TmpOidName;
-    int TmpOidNameLen = 0;
-
-    /* Find the next OID. */
-    VarPtr = PDU->variables;
-
-    ParseFn = oidlist_Next(VarPtr->name, VarPtr->name_length,
-                         &(TmpOidName), (long *)&(TmpOidNameLen));
+    struct snmp_pdu *Answer = NULL;
+    variable_list *VarPtr, *VarNew = NULL;
+    variable_list **VarPtrP, **RespVars;
+    int index = 0;
+    oid_ParseFn *ParseFn;
+
+    debug(49, 9) ("Received a %d PDU\n", PDU->command);
+
+    /* Create a response */
+    Answer = snmp_pdu_create(SNMP_PDU_RESPONSE);
+    if (Answer == NULL)
+	return (NULL);
+    Answer->reqid = PDU->reqid;
+    Answer->errindex = 0;
+
+    if (PDU->command == SNMP_PDU_GET) {
+
+	RespVars = &(Answer->variables);
+	/* Loop through all variables */
+	for (VarPtrP = &(PDU->variables);
+	    *VarPtrP;
+	    VarPtrP = &((*VarPtrP)->next_variable)) {
+	    VarPtr = *VarPtrP;
+
+	    index++;
+
+	    /* Find the parsing function for this variable */
+	    ParseFn = oidlist_Find(VarPtr->name, VarPtr->name_length);
+
+	    if (ParseFn == NULL) {
+		Answer->errstat = SNMP_ERR_NOSUCHNAME;
+		debug(49, 5) ("snmp_agent_response: No such oid. ");
+	    } else
+		VarNew = (*ParseFn) (VarPtr, (long *) &(Answer->errstat));
+
+	    /* Was there an error? */
+	    if ((Answer->errstat != SNMP_ERR_NOERROR) ||
+		(VarNew == NULL)) {
+		Answer->errindex = index;
+		debug(49, 5) ("snmp_agent_parse: successful.\n");
+		/* Just copy the rest of the variables.  Quickly. */
+		*RespVars = VarPtr;
+		*VarPtrP = NULL;
+		return (Answer);
+	    }
+	    /* No error.  Insert this var at the end, and move on to the next.
+	     */
+	    *RespVars = VarNew;
+	    RespVars = &(VarNew->next_variable);
+	}
 
-    if (ParseFn == NULL) {
-      Answer->errstat = SNMP_ERR_NOSUCHNAME;
-#ifdef DEBUG_SNMP
-      printf("No such oid: ");
-      print_oid(VarPtr->name, VarPtr->name_length);
-#endif
-    } else {
-      xfree(VarPtr->name);
-      VarPtr->name = TmpOidName;
-      VarPtr->name_length = TmpOidNameLen;      
-      VarNew = (*ParseFn)(VarPtr, (long *)&(Answer->errstat));
-    }
+	return (Answer);
+    } else if (PDU->command == SNMP_PDU_GETNEXT) {
+	oid *TmpOidName;
+	int TmpOidNameLen = 0;
+
+	/* Find the next OID. */
+	VarPtr = PDU->variables;
+
+	ParseFn = oidlist_Next(VarPtr->name, VarPtr->name_length,
+	    &(TmpOidName), (long *) &(TmpOidNameLen));
+
+	if (ParseFn == NULL) {
+	    Answer->errstat = SNMP_ERR_NOSUCHNAME;
+	    debug(49, 9) ("No such oid: ");
+	    print_oid(VarPtr->name, VarPtr->name_length);
+	} else {
+	    xfree(VarPtr->name);
+	    VarPtr->name = TmpOidName;
+	    VarPtr->name_length = TmpOidNameLen;
+	    VarNew = (*ParseFn) (VarPtr, (long *) &(Answer->errstat));
+	}
 
-    /* Was there an error? */
-    if (Answer->errstat != SNMP_ERR_NOERROR) {
-      Answer->errindex = 1;
+	/* Was there an error? */
+	if (Answer->errstat != SNMP_ERR_NOERROR) {
+	    Answer->errindex = 1;
 
-      /* Just copy this variable */
-      Answer->variables = VarPtr;
-      PDU->variables = NULL;
-    } else {
-      Answer->variables = VarNew;
-    }
+	    /* Just copy this variable */
+	    Answer->variables = VarPtr;
+	    PDU->variables = NULL;
+	} else {
+	    Answer->variables = VarNew;
+	}
 
-    /* Done.  Return this PDU */
-    return(Answer);
-  } /* end SNMP_PDU_GETNEXT */
-  
-#ifdef DEBUG_SNMP
-  printf("Ignoring PDU %d\n", PDU->command);
-#endif
-  snmp_free_pdu(Answer);
-  return(NULL);
+	/* Done.  Return this PDU */
+	return (Answer);
+    }				/* end SNMP_PDU_GETNEXT */
+#
+    debug(49, 9) ("Ignoring PDU %d\n", PDU->command);
+    snmp_free_pdu(Answer);
+    return (NULL);
 }
 
-char private_community[]= "public";
+char private_community[] = "public";
 
-int community_check(char *b)
+int
+community_check(char *b)
 {
-  return(!strcmp(b, private_community));
+    return (!strcmp(b, private_community));
 }
 
-int init_agent_auth()
+int
+init_agent_auth()
 {
-  Session = (struct snmp_session *)xmalloc(sizeof(struct snmp_session));
-  if (Session == NULL) {
-    perror("malloc");
-    return 3;
-  }
-
-  Session->Version=SNMP_VERSION_1;	
-  Session->authenticator = NULL;
-  Session->community = (u_char *)xstrdup("public");
-  Session->community_len = 6;
-	return 1;
+    Session = (struct snmp_session *) xmalloc(sizeof(struct snmp_session));
+    if (Session == NULL) {
+	perror("malloc");
+	return 3;
+    }
+    Session->Version = SNMP_VERSION_1;
+    Session->authenticator = NULL;
+    Session->community = (u_char *) xstrdup("public");
+    Session->community_len = 6;
+    return 1;
 }
 
 /************************************************************************

 * the pointer passed to snmp_open()).  On any error, NULL is returned
 * and snmp_errno is set to the appropriate error code.
 */
struct snmp_session *
snmp_open(struct snmp_session *session)
{
    struct session_list *slp;
    struct snmp_internal_session *isp;
    u_char *cp;
    int sd;
    u_long addr;
    struct sockaddr_in me;
    struct hostent *hp;
    struct servent *servp;
    extern int check_received_pkt();

    /* Copy session structure and link into list */
    slp = xcalloc(1, sizeof(struct session_list));
    slp->internal = isp = xcalloc(1, sizeof(struct snmp_internal_session));
    memset(isp, '\0', sizeof(struct snmp_internal_session));
    slp->internal->sd = -1;	/* mark it not set */
    slp->session = xcalloc(1, sizeof(struct snmp_session));
    xmemcpy(slp->session, session, sizeof(struct snmp_session));
    session = slp->session;
    /* now link it in. */
    slp->next = Sessions;
    Sessions = slp;

    /*
     * session now points to the new structure that still contains pointers to
     * data allocated elsewhere.  Some of this data is copied to space malloc'd
     * here, and the pointer replaced with the new one.
     */

    if (session->peername != NULL) {
	cp = xcalloc(1, (unsigned) strlen(session->peername) + 1);
	strcpy((char *) cp, session->peername);
	session->peername = (char *) cp;
    }
    if (session->retries == SNMP_DEFAULT_RETRIES)
	session->retries = SNMP_API_DEFAULT_RETRIES;
    if (session->timeout == SNMP_DEFAULT_TIMEOUT)
	session->timeout = SNMP_API_DEFAULT_TIMEOUT;
    if (session->MMS == 0)
	session->MMS = DEFAULT_MMS;
    isp->requests = NULL;


    /* Fill in defaults if necessary */
    if (session->community_len != SNMP_DEFAULT_COMMUNITY_LEN) {
	if (*session->community == '+') {
	    session->community_len--;
	    cp = xcalloc(1, (unsigned) session->community_len);
	    bcopy((char *) session->community + 1, (char *) cp,
		session->community_len);
	    session->version = SNMP_VERSION_2C;
	} else {
	    cp = xcalloc(1, (unsigned) session->community_len);
	    bcopy((char *) session->community, (char *) cp,
		session->community_len);
	}

    } else {
	session->community_len = strlen(DEFAULT_COMMUNITY);
	cp = xcalloc(1, (unsigned) session->community_len);
	xmemcpy(cp, DEFAULT_COMMUNITY, session->community_len);
    }

    /* Set up connections */
    sd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sd < 0) {
	perror("socket");
	snmp_errno = SNMPERR_GENERR;
	if (!snmp_close(session)) {
#if NO_PRINTFS
	    fprintf(stderr, "Couldn't abort session: %s. Exiting\n", api_errstring(snmp_errno));
#endif
	    exit(1);
	}
	return 0;
    }
    isp->sd = sd;

    if (session->peername != SNMP_DEFAULT_PEERNAME) {
	if ((addr = inet_addr(session->peername)) != -1) {
	    xmemcpy(&isp->addr.sin_addr, &addr, sizeof(isp->addr.sin_addr));
	} else {
	    hp = gethostbyname(session->peername);
	    if (hp == NULL) {
#if NO_PRINTFS
		fprintf(stderr, "unknown host: %s\n", session->peername);
#endif
		snmp_errno = SNMPERR_BAD_ADDRESS;
		if (!snmp_close(session)) {
#if NO_PRINTFS
		    fprintf(stderr, "Couldn't abort session: %s. Exiting\n", api_errstring(snmp_errno));
#endif
		    exit(2);
		}
		return 0;
	    } else {
		xmemcpy(&isp->addr.sin_addr, hp->h_addr, hp->h_length);
	    }
	}
	isp->addr.sin_family = AF_INET;
	if (session->remote_port == SNMP_DEFAULT_REMPORT) {
	    /*servp = getservbyname("snmp", "udp"); */
	    servp = NULL;
	    if (servp != NULL) {
		isp->addr.sin_port = servp->s_port;
	    } else {
		isp->addr.sin_port = htons(SNMP_PORT);
	    }
	} else {
	    isp->addr.sin_port = htons(session->remote_port);
	}
    } else {
	isp->addr.sin_addr.s_addr = SNMP_DEFAULT_ADDRESS;
    }

    me.sin_family = AF_INET;
    me.sin_addr.s_addr = INADDR_ANY;
    me.sin_port = htons(session->local_port);
    if (bind(sd, (struct sockaddr *) &me, sizeof(me)) != 0) {
	perror("bind");
	snmp_errno = SNMPERR_BAD_LOCPORT;
	if (!snmp_close(session)) {
#if NO_PRINTFS
	    fprintf(stderr, "Couldn't abort session: %s. Exiting\n",
		api_errstring(snmp_errno));
#endif
	    exit(3);
	}
	return 0;
    }
    if (*cp == '/') {
	session->authenticator = check_received_pkt;
	sync_with_agent(session);
	parse_app_community_string(session);
	session->qoS |= USEC_QOS_GENREPORT;
    }
    /* replace comm pointer with pointer to new data: */
    session->community = cp;

    return session;
}

static void
sync_with_agent(struct snmp_session *session)
{
    struct snmp_pdu *pdu, *response = 0;
    int status;

    session->qoS = USEC_QOS_GENREPORT;
    session->userLen = 6;
    session->version = SNMP_VERSION_2;
    strcpy((char *)session->userName, "public");

    snmp_synch_setup(session);
    pdu = snmp_pdu_create(GET_REQ_MSG);
    status = snmp_synch_response(session, pdu, &response);

    if (status == STAT_SUCCESS) {
	memcpy(session->agentID, response->params.agentID, 12);

	/* save the clocks -- even though they are not authentic */
	session->agentBoots = response->params.agentBoots;
	session->agentTime = response->params.agentTime;
	session->agentClock = response->params.agentTime - time(NULL);

    } else {
#if NO_PRINTFS
	if (status == STAT_TIMEOUT) {
	    printf("No Response from %s\n", session->peername);
	} else {		/* status == STAT_ERROR */
	    printf("An error occurred, Quitting\n");
	}
#endif
	exit(-1);
    }

    /** freed to early: 
      snmp_free_pdu(pdu);
      if (response) snmp_free_pdu(response);
     **/
}

/*
 * Unlink one element from input request list,
 * then free it and it's pdu.
 */
static void
free_one_request(struct snmp_internal_session *isp, struct request_list *orp)
{
    struct request_list *rp;
    if (!orp)
	return;
    if (isp->requests == orp) {
	isp->requests = orp->next_request;	/* unlink head */
    } else {
	for (rp = isp->requests; rp; rp = rp->next_request) {
	    if (rp->next_request == orp) {
		rp->next_request = orp->next_request;	/* unlink element */
		break;
	    }
	}
    }
    if (orp->pdu != NULL) {
	snmp_free_pdu(orp->pdu);
    }
    xfree((char *) orp);
}

/*
 * Free each element in the input request list.
 */
static void
free_request_list(struct request_list *rp)
{
    struct request_list *orp;

    while (rp) {
	orp = rp;
	rp = rp->next_request;
	if (orp->pdu != NULL)
	    snmp_free_pdu(orp->pdu);
	xfree((char *) orp);
    }
}

/*
 * Close the input session.  Frees all data allocated for the session,
 * dequeues any pending requests, and closes any sockets allocated for
 * the session.  Returns 0 on error, 1 otherwise.
 */
int
snmp_close(struct snmp_session *session)
{
    struct session_list *slp = NULL, *oslp = NULL;

    if (Sessions->session == session) {		/* If first entry */
	slp = Sessions;
	Sessions = slp->next;
    } else {
	for (slp = Sessions; slp; slp = slp->next) {
	    if (slp->session == session) {
		if (oslp)	/* if we found entry that points here */
		    oslp->next = slp->next;	/* link around this entry */
		break;
	    }
	    oslp = slp;
	}
    }
    /* If we found the session, free all data associated with it */
    if (slp) {
	if (slp->session->community != NULL)
	    xfree((char *) slp->session->community);
	if (slp->session->peername != NULL)
	    xfree((char *) slp->session->peername);
	xfree((char *) slp->session);
	if (slp->internal->sd != -1)
	    close(slp->internal->sd);
	free_request_list(slp->internal->requests);
	xfree((char *) slp->internal);
	xfree((char *) slp);
    } else {
	snmp_errno = SNMPERR_BAD_SESSION;
	return 0;
    }
    return 1;
}

/*
 * Takes a session and a pdu and serializes the ASN PDU into the area
 * pointed to by packet.  out_length is the size of the data area available.
 * Returns the length of the completed packet in out_length.  If any errors
 * occur, -1 is returned.  If all goes well, 0 is returned.
 */
int
snmp_build(
    struct snmp_session *session,
    struct snmp_pdu *pdu,
    u_char * packet,
    int *out_length,
    int is_agent)
{
    u_char buf[PACKET_LENGTH];
    u_char *cp;
    struct variable_list *vp;
    int length;
    int totallength;

    length = *out_length;
    cp = packet;
    for (vp = pdu->variables; vp; vp = vp->next_variable) {
	cp = snmp_build_var_op(cp, vp->name, &vp->name_length, vp->type, vp->val_len, (u_char *) vp->val.string, &length);
	if (cp == NULL)
	    return -1;
    }
    totallength = cp - packet;

    length = PACKET_LENGTH;
    cp = asn_build_header(buf, &length, (u_char) (ASN_SEQUENCE | ASN_CONSTRUCTOR), totallength);
    if (cp == NULL)
	return -1;
    xmemcpy(cp, packet, totallength);
    totallength += cp - buf;

    length = *out_length;
    if (pdu->command != TRP_REQ_MSG) {
	/* request id */
	cp = asn_build_int(packet, &length,
	    (u_char) (ASN_UNIVERSAL | ASN_PRIMITIVE | ASN_INTEGER),
	    (long *) &pdu->reqid, sizeof(pdu->reqid));
	if (cp == NULL)
	    return -1;
	/* error status */
	cp = asn_build_int(cp, &length,
	    (u_char) (ASN_UNIVERSAL | ASN_PRIMITIVE | ASN_INTEGER),
	    (long *) &pdu->errstat, sizeof(pdu->errstat));
	if (cp == NULL)
	    return -1;
	/* error index */
	cp = asn_build_int(cp, &length,
	    (u_char) (ASN_UNIVERSAL | ASN_PRIMITIVE | ASN_INTEGER),
	    (long *) &pdu->errindex, sizeof(pdu->errindex));
	if (cp == NULL)
	    return -1;
    } else {			/* this is a trap message */
	/* enterprise */
	cp = asn_build_objid(packet, &length,
	    (u_char) (ASN_UNIVERSAL | ASN_PRIMITIVE | ASN_OBJECT_ID),
	    (oid *) pdu->enterprise, pdu->enterprise_length);
	if (cp == NULL)
	    return -1;
	/* agent-addr */
	cp = asn_build_string(cp, &length, (u_char) IPADDRESS,
	    (u_char *) & pdu->agent_addr.sin_addr.s_addr, sizeof(pdu->agent_addr.sin_addr.s_addr));
	if (cp == NULL)
	    return -1;
	/* generic trap */
	cp = asn_build_int(cp, &length,
	    (u_char) (ASN_UNIVERSAL | ASN_PRIMITIVE | ASN_INTEGER),
	    (long *) &pdu->trap_type, sizeof(pdu->trap_type));
	if (cp == NULL)
	    return -1;
	/* specific trap */
	cp = asn_build_int(cp, &length,
	    (u_char) (ASN_UNIVERSAL | ASN_PRIMITIVE | ASN_INTEGER),
	    (long *) &pdu->specific_type, sizeof(pdu->specific_type));
	if (cp == NULL)
	    return -1;
	/* timestamp  */
	cp = asn_build_int(cp, &length, (u_char) TIMETICKS,
	    (long *) &pdu->time, sizeof(pdu->time));
	if (cp == NULL)
	    return -1;
    }
    if (length < totallength)
	return -1;
    xmemcpy(cp, buf, totallength);
    totallength += cp - packet;

    length = PACKET_LENGTH;
    cp = asn_build_header(buf, &length, (u_char) pdu->command, totallength);
    if (cp == NULL)
	return -1;
    if (length < totallength)
	return -1;
    xmemcpy(cp, packet, totallength);
    totallength += cp - buf;

    length = *out_length;

    cp = snmp_auth_build(packet, &length, session, is_agent, totallength);
    if (cp == NULL)
	return -1;
    if ((*out_length - (cp - packet)) < totallength)
	return -1;
    xmemcpy(cp, buf, totallength);
    totallength += cp - packet;
    *out_length = totallength;

    if (session->qoS & USEC_QOS_AUTH)
	md5Digest(packet, totallength, cp - (session->contextLen + 16),
	    cp - (session->contextLen + 16));

    return 0;
}

/*
 * Parses the packet received on the input session, and places the data into
 * the input pdu.  length is the length of the input packet.  If any errors
 * are encountered, -1 is returned.  Otherwise, a 0 is returned.
 */
static int
snmp_parse(
    struct snmp_session *session,
    struct snmp_pdu *pdu,
    u_char * data,
    int length)
{
    u_char msg_type;
    u_char type;
    u_char *var_val;
    long version;
    int len, four;
    u_char community[256];
    int community_length = 256;
    struct variable_list *vp = 0;
    oid objid[MAX_NAME_LEN], *op;
    u_char *origdata = data;
    int origlength = length;
    int ret = 0;
    u_char *save_data;

    /* authenticates message and returns length if valid */
    data = snmp_auth_parse(data, &length, community, &community_length, &version);
    if (data == NULL)
	return -1;

    if (version != SNMP_VERSION_1 && version != SNMP_VERSION_2C && version != SNMP_VERSION_2) {
#if NO_PRINTFS
	fprintf(stderr, "Wrong version: %ld\n", version);
#endif
	return -1;
    }
    save_data = data;

    data = asn_parse_header(data, &length, &msg_type);
    if (data == NULL)
	return -1;
    pdu->command = msg_type;

    if (session->authenticator) {
	ret = session->authenticator(origdata, origlength, save_data - community_length,
	    community_length, session, pdu);
	if (ret < 0)
	    return ret;
    }
    if (pdu->command != TRP_REQ_MSG) {
	data = asn_parse_int(data, &length, &type, (long *) &pdu->reqid, sizeof(pdu->reqid));
	if (data == NULL)
	    return -1;
	data = asn_parse_int(data, &length, &type, (long *) &pdu->errstat, sizeof(pdu->errstat));
	if (data == NULL)
	    return -1;
	data = asn_parse_int(data, &length, &type, (long *) &pdu->errindex, sizeof(pdu->errindex));
	if (data == NULL)
	    return -1;
    } else {
	pdu->enterprise_length = MAX_NAME_LEN;
	data = asn_parse_objid(data, &length, &type, objid, &pdu->enterprise_length);
	if (data == NULL)
	    return -1;
	pdu->enterprise = xcalloc(1, pdu->enterprise_length * sizeof(oid));
	xmemcpy(pdu->enterprise, objid, pdu->enterprise_length * sizeof(oid));

	four = 4;
	data = asn_parse_string(data, &length, &type, (u_char *) & pdu->agent_addr.sin_addr.s_addr, &four);
	if (data == NULL)
	    return -1;
	data = asn_parse_int(data, &length, &type, (long *) &pdu->trap_type, sizeof(pdu->trap_type));
	if (data == NULL)
	    return -1;
	data = asn_parse_int(data, &length, &type, (long *) &pdu->specific_type, sizeof(pdu->specific_type));
	if (data == NULL)
	    return -1;
	data = asn_parse_int(data, &length, &type, (long *) &pdu->time, sizeof(pdu->time));
	if (data == NULL)
	    return -1;
    }
    data = asn_parse_header(data, &length, &type);
    if (data == NULL)
	return -1;
    if (type != (u_char) (ASN_SEQUENCE | ASN_CONSTRUCTOR))
	return -1;
    while ((int) length > 0) {
	if (pdu->variables == NULL) {
	    pdu->variables = vp = xcalloc(1, sizeof(struct variable_list));
	} else {
	    vp->next_variable = xcalloc(1, sizeof(struct variable_list));
	    vp = vp->next_variable;
	}
	vp->next_variable = NULL;
	vp->val.string = NULL;
	vp->name = NULL;
	vp->name_length = MAX_NAME_LEN;
	data = snmp_parse_var_op(data, objid, &vp->name_length, &vp->type, &vp->val_len, &var_val, (int *) &length);
	if (data == NULL)
	    return -1;
	op = xcalloc(1, (unsigned) vp->name_length * sizeof(oid));
	xmemcpy(op, objid, vp->name_length * sizeof(oid));
	vp->name = op;

	len = PACKET_LENGTH;
	switch ((short) vp->type) {
	case ASN_INTEGER:
	    vp->val.integer = xcalloc(1, sizeof(long));
	    vp->val_len = sizeof(long);
	    asn_parse_int(var_val, &len, &vp->type, (long *) vp->val.integer, sizeof(vp->val.integer));
	    break;
	case COUNTER:
	case GAUGE:
	case TIMETICKS:
	case UINTEGER:
	    vp->val.integer = xcalloc(1, sizeof(unsigned long));
	    vp->val_len = sizeof(unsigned long);
	    asn_parse_unsigned_int(var_val, &len, &vp->type, (unsigned long *) vp->val.integer, sizeof(vp->val.integer));
	    break;
	case COUNTER64:
	    vp->val.counter64 = xcalloc(1, sizeof(struct counter64));
	    vp->val_len = sizeof(struct counter64);
	    asn_parse_unsigned_int64(var_val, &len, &vp->type,
		(struct counter64 *) vp->val.counter64,
		sizeof(*vp->val.counter64));
	    break;
	case ASN_OCTET_STR:
	case IPADDRESS:
	case OPAQUE:
	case NSAP:
	    vp->val.string = xcalloc(1, (unsigned) vp->val_len);
	    asn_parse_string(var_val, &len, &vp->type, vp->val.string, &vp->val_len);
	    break;
	case ASN_OBJECT_ID:
	    vp->val_len = MAX_NAME_LEN;
	    asn_parse_objid(var_val, &len, &vp->type, objid, &vp->val_len);
	    vp->val_len *= sizeof(oid);
	    vp->val.objid = xcalloc(1, (unsigned) vp->val_len);
	    xmemcpy(vp->val.objid, objid, vp->val_len);
	    break;
	case SNMP_NOSUCHOBJECT:
	case SNMP_NOSUCHINSTANCE:
	case SNMP_ENDOFMIBVIEW:
	case ASN_NULL:
	    break;
	default:
#if NO_PRINTFS
	    fprintf(stderr, "bad type returned (%x)\n", vp->type);
#endif
	    break;
	}
    }
    return ret;
}

/*

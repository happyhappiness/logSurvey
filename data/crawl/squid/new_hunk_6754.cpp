 * the pointer passed to snmp_open()).  On any error, NULL is returned
 * and snmp_errno is set to the appropriate error code.
 */
struct snmp_session *snmp_open(struct snmp_session *session)
{
  struct session_list *slp;
  struct snmp_internal_session *isp;
  u_char *cp;
  int sd;
  u_int addr;
  struct sockaddr_in	me;
  struct hostent *hp;
  struct servent *servp;

  if (Reqid == 0)
    init_snmp();

  /* Copy session structure and link into list */
  slp = (struct session_list *)xmalloc(sizeof(struct session_list));
  if (slp == NULL) {
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }

  /* Internal session */
  isp = (struct snmp_internal_session *)xmalloc(sizeof(struct snmp_internal_session));
  if (isp == NULL) {
    xfree(slp);
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }

  slp->internal = isp;
  memset((char *)isp, '\0', sizeof(struct snmp_internal_session));
  slp->internal->sd = -1; /* mark it not set */

  /* The actual session */
  slp->session = (struct snmp_session *)xmalloc(sizeof(struct snmp_session));
  if (slp->session == NULL) {
    xfree(isp);
    xfree(slp);
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }

  xmemcpy((char *)slp->session, (char *)session, sizeof(struct snmp_session));
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
    cp = (u_char *)xmalloc((unsigned)strlen(session->peername) + 1);
    if (cp == NULL) {
      xfree(slp->session);
      xfree(isp);
      xfree(slp);
      snmp_set_api_error(SNMPERR_OS_ERR);
      return(NULL);
    }

    strcpy((char *)cp, session->peername);
    session->peername = (char *)cp;
  }

  /* Fill in defaults if necessary */
  if (session->community_len != SNMP_DEFAULT_COMMUNITY_LEN) {
    cp = (u_char *)xmalloc((unsigned)session->community_len);
    if (cp)
      xmemcpy((char *)cp, (char *)session->community, session->community_len);
  } else {
    session->community_len = strlen(DEFAULT_COMMUNITY);
    cp = (u_char *)xmalloc((unsigned)session->community_len);
    if (cp)
      xmemcpy((char *)cp, (char *)DEFAULT_COMMUNITY, 
	     session->community_len);
  }
  if (cp == NULL) {
    xfree(session->peername);
    xfree(slp->session);
    xfree(isp);
    xfree(slp);
    snmp_set_api_error(SNMPERR_OS_ERR);
    return(NULL);
  }

  session->community = cp;	/* replace pointer with pointer to new data */

  if (session->retries == SNMP_DEFAULT_RETRIES)
    session->retries = DEFAULT_RETRIES;
  if (session->timeout == SNMP_DEFAULT_TIMEOUT)
    session->timeout = DEFAULT_TIMEOUT;
  isp->requests = NULL;

  /* Set up connections */
  sd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sd < 0) {
    perror("socket");
    snmp_set_api_error(SNMPERR_OS_ERR);
    if (!snmp_close(session)) {
      snmplib_debug(5, "Couldn't abort session: %s. Exiting\n", 
	      api_errstring(snmp_errno));
      exit(1);
    }
    return(NULL);
  }

#ifdef SO_BSDCOMPAT
  /* Patch for Linux.  Without this, UDP packets that fail get an ICMP
   * response.  Linux turns the failed ICMP response into an error message
   * and return value, unlike all other OS's.
   */
  {
    int one=1;
    setsockopt(sd, SOL_SOCKET, SO_BSDCOMPAT, &one, sizeof(one));
  }
#endif /* SO_BSDCOMPAT */

  isp->sd = sd;
  if (session->peername != SNMP_DEFAULT_PEERNAME) {
    if ((addr = inet_addr(session->peername)) != -1) {
      xmemcpy((char *)&isp->addr.sin_addr, (char *)&addr, 
	     sizeof(isp->addr.sin_addr));
    } else {
      hp = gethostbyname(session->peername);
      if (hp == NULL){
	snmplib_debug(3, "unknown host: %s\n", session->peername);
	snmp_errno = SNMPERR_BAD_ADDRESS;
	if (!snmp_close(session)){
	  snmplib_debug(3, "Couldn't abort session: %s. Exiting\n", 
		  api_errstring(snmp_errno));
	  exit(2);
	}
	return(NULL);
      } else {
	xmemcpy((char *)&isp->addr.sin_addr, (char *)hp->h_addr, 
	       hp->h_length);
      }
    }

    isp->addr.sin_family = AF_INET;
    if (session->remote_port == SNMP_DEFAULT_REMPORT) {
      servp = getservbyname("snmp", "udp");
      if (servp != NULL){
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

  memset(&me, '\0', sizeof(me));
  me.sin_family = AF_INET;
  me.sin_addr.s_addr = INADDR_ANY;
  me.sin_port = htons(session->local_port);
  if (bind(sd, (struct sockaddr *)&me, sizeof(me)) != 0) {
    perror("bind");
    snmp_errno = SNMPERR_BAD_LOCPORT;
    if (!snmp_close(session)) {
      snmplib_debug(3, "Couldn't abort session: %s. Exiting\n", 
	      api_errstring(snmp_errno));
      exit(3);
    }
    return(NULL);
  }
  return(session);
}



/*
 * Close the input session.  Frees all data allocated for the session,
 * dequeues any pending requests, and closes any sockets allocated for
 * the session.  Returns 0 on error, 1 otherwise.
 */
int snmp_close(struct snmp_session *session)
{
  struct session_list *slp = NULL, *oslp = NULL;

  if (Sessions->session == session) {	/* If first entry */
    slp = Sessions;
    Sessions = slp->next;
  } else {
    for(slp = Sessions; slp; slp = slp->next){
      if (slp->session == session){
	if (oslp)   /* if we found entry that points here */
	  oslp->next = slp->next;	/* link around this entry */
	break;
      }
      oslp = slp;
    }
  }

  /* If we found the session, free all data associated with it */
  if (slp) {
    if (slp->session->community != NULL)
      xfree((char *)slp->session->community);
    if(slp->session->peername != NULL)
      xfree((char *)slp->session->peername);
    xfree((char *)slp->session);
    if (slp->internal->sd != -1)
      close(slp->internal->sd);
    free_request_list(slp->internal->requests);
    xfree((char *)slp->internal);
    xfree((char *)slp);
  } else {
    snmp_errno = SNMPERR_BAD_SESSION;
    return(0);
  }
  return(1);
}

/*
 * Takes a session and a pdu and serializes the ASN PDU into the area
 * pointed to by packet.  out_length is the size of the data area available.
 * Returns the length of the encoded packet in out_length.  If an error
 * occurs, -1 is returned.  If all goes well, 0 is returned.
 */
int
snmp_build(session, pdu, packet, out_length)
    struct snmp_session	*session;
    struct snmp_pdu	*pdu;
    u_char *packet;
    int			*out_length;
{
    u_char *bufp;

    bufp = snmp_msg_Encode(packet, out_length,
			   session->community, session->community_len, 
			   session->Version,
			   pdu);
    snmplib_debug(8,"LIBSNMP: snmp_build():  Packet len difference %d, returning %d (requid %d)\n",
	   (bufp - packet), *out_length, pdu->reqid);

    if (bufp == NULL)
      return(-1);

    return(0);
}

/*
 * Parses the packet recieved on the input session, and places the data into
 * the input pdu.  length is the length of the input packet.  If any errors
 * are encountered, NULL is returned.  If not, the community is.
 */
u_char *snmp_parse(struct snmp_session *session, 
	       struct snmp_pdu *pdu, 
	       u_char *data, 
	       int length)
{
    u_char Community[128];
    u_char *bufp;
    int CommunityLen = 128;

    /* Decode the entire message. */
    data = snmp_msg_Decode(data, &length, 
			   Community, &CommunityLen, 
			   &session->Version, pdu);
    if (data == NULL)
	return(NULL);

   bufp = (u_char *)xmalloc(CommunityLen+1);
   if (bufp == NULL)
    return(NULL);

   strcpy((char *)bufp, (char *)Community);
   return(bufp);
}

/*

int
init_agent_auth(void)
{
    char hostname[256];
    struct hostent *hp;
    FILE *f;
    /* comes from snmpd.c: */

    /* agentID is based on enterprise number and local IP address */
    /* not "settable, thus, if agentBoots=0xffffffff, then all keys should be changed */
    if (gethostname(hostname, sizeof(hostname)) != 0) {
	fatal("snmpd: cannot get hostname");
	return -1;
    }
    if ((hp = gethostbyname(hostname)) == NULL) {
	fatal("snmpd: cannot determine local hostname");
	return -1;
    }
    _agentID[3] = 35;		/* BNR private enterprise number */
    xmemcpy(&_agentID[4], hp->h_addr, hp->h_length);

    if (Config.Snmp.agentInfo == NULL) {
	debug(49, 1) ("init_agent_auth: WARNING: Config.Snmp.agentInfo == NULL\n");
	return -1;
    }
    if ((f = fopen(Config.Snmp.agentInfo, "r+")) == NULL) {
	debug(49, 5) ("init_agent_auth: Agent not installed properly, cannot open '%s'\n",
	    Config.Snmp.agentInfo);
	debug(49, 5) ("init_agent_auth: Create a empty file '%s'. This is used for\n",
	    Config.Snmp.agentInfo);
	debug(49, 5) ("NV store of the agentBoots object.\n");
	return -1;
    }
    fscanf(f, "%ld", &_agentBoots);
    _agentBoots++;
    fseek(f, 0, 0);
    fprintf(f, "%ld\n", _agentBoots);
    fclose(f);


    _agentStartTime = -time(NULL);

    _agentSize = SNMP_MAX_LEN;

    return 0;
}

int
snmp_agent_parse(sn_data, length, out_sn_data, out_length, sourceip, ireqid)
     u_char *sn_data;
     int length;
     u_char *out_sn_data;
     int *out_length;
     u_long sourceip;		/* possibly for authentication */
     long *ireqid;
{
    u_char msgtype, type;
    long zero = 0;
    long reqid, errstat, errindex, dummyindex;
    u_char *out_auth, *out_header, *out_reqid;
    u_char *startData = sn_data;
    int startLength = length;
    long version;
    u_char *origsn_data = sn_data;
    int origlen = length;
    usecEntry *ue;
    int ret = 0, packet_len;

    sidlen = SID_MAX_LEN;
    sn_data = snmp_auth_parse(sn_data, &length, sid, &sidlen, &version);
    if (sn_data == NULL) {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("snmp_agent_parse: bad auth encoding\n");
	return 0;
    }
    if (version != SNMP_VERSION_1 && version != SNMP_VERSION_2C && version != SNMP_VERSION_2) {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("snmp_agent_parse: wrong version\n");
#ifdef linux
	snmp_inbadversions++;
#endif
	return 0;
    }
    if (version == SNMP_VERSION_2C || version == SNMP_VERSION_2) {
	if (version == SNMP_VERSION_2) {
	    ret = check_auth(session, origsn_data, origlen, sn_data - sidlen, sidlen, &ue);
	    *out_length = (SNMP_MAX_LEN < session->MMS) ? SNMP_MAX_LEN : session->MMS;
	    session->MMS = SNMP_MAX_LEN;

	} else if (version == SNMP_VERSION_2C) {
	    ret = get_community(sid);
	    session->version = SNMP_VERSION_2C;
	}
	if (ret < 0) {
	    increment_stat(-ret);
	    if ((sn_data = asn_parse_header(sn_data, &length, &msgtype))
		&& asn_parse_int(sn_data, &length, &type, &reqid, sizeof(reqid))) {
		if (msgtype == REPORT_MSG)
		    return 0;
		if (!(session->qoS & USEC_QOS_GENREPORT))
		    return 0;
		session->agentBoots = _agentBoots;
		session->agentClock = _agentStartTime;
		xmemcpy(session->agentID, _agentID, 12);
		session->MMS = SNMP_MAX_LEN;
		create_report(session, out_sn_data, out_length, -ret, reqid);
		return 1;
	    } else {
		debug(49, 5) ("snmp_agent_parse: asn_parse failed\n");
		return 0;
	    }
	} else if (ret > 0) {
	    increment_stat(ret);
	    debug(49, 5) ("snmp_agent_parse: authorization failed ret=%d\n", ret);
	    return 0;
	}
    } else if (version == SNMP_VERSION_1) {
	if ((ret = get_community(sid)) != 0) {
	    increment_stat(ret);
	    debug(49, 5) ("snmp_agent_parse: get_community failed\n");
	    return 0;
	}
	session->version = SNMP_VERSION_1;
    } else {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("snmp_agent_parse : wrong version\n");
#ifdef linux
	snmp_inbadversions++;
#endif
	return 0;
    }

    sn_data = asn_parse_header(sn_data, &length, &msgtype);
    if (sn_data == NULL) {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("snmp_agent_parse: bad header\n");
	return 0;
    }
#ifdef linux
    /* XXX: increment by total number of vars at correct place: */
    snmp_intotalreqvars++;
    if (msgtype == GET_REQ_MSG)
	snmp_ingetrequests++;
    if (msgtype == GETNEXT_REQ_MSG)
	snmp_ingetnexts++;
    if (msgtype == SET_REQ_MSG)
	snmp_insetrequests++;
#endif

    if (msgtype == GETBULK_REQ_MSG) {
	if (session->version == SNMP_VERSION_1) {
	    debug(49, 5) ("snmp_agent_parse: getbulk but version 1\n");
	    return 0;
	}
    } else if (msgtype != GET_REQ_MSG && msgtype != GETNEXT_REQ_MSG && msgtype != SET_REQ_MSG) {
	debug(49, 5) ("snmp_agent_parse: unknown request type\n");
	return 0;
    }
    sn_data = asn_parse_int(sn_data, &length, &type, &reqid, sizeof(reqid));
    if (sn_data == NULL) {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("snmp_agent_parse: bad parse of reqid\n");
	return 0;
    }
    sn_data = asn_parse_int(sn_data, &length, &type, &errstat, sizeof(errstat));
    if (sn_data == NULL) {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("snmp_agent_parse: bad parse of errstat\n");
#ifdef linux
	snmp_inasnparseerrors++;
#endif
	return 0;
    }
    sn_data = asn_parse_int(sn_data, &length, &type, &errindex, sizeof(errindex));
    if (sn_data == NULL) {
	increment_stat(SNMP_STAT_ENCODING_ERRORS);
	debug(49, 5) ("bad parse of errindex\n");
	return 0;
    }
    /*

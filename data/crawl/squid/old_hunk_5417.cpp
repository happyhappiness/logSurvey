    case ACL_URL_PORT:
    case ACL_URL_REGEX:
	/* These ACL types require checklist->request */
	if (NULL == r) {
	    debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
		" HTTP request -- access denied.\n", ae->name);
	    return 0;
	}
	break;
    default:
	break;
    }
    debug(28, 3) ("aclMatchAcl: checking '%s'\n", ae->cfgline);
    switch (ae->type) {
    case ACL_SRC_IP:
	return aclMatchIp(&ae->data, checklist->src_addr);
	/* NOTREACHED */
    case ACL_MY_IP:
	return aclMatchIp(&ae->data, checklist->my_addr);
	/* NOTREACHED */
    case ACL_DST_IP:
	ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
	if (ia) {
	    for (k = 0; k < (int) ia->count; k++) {
		if (aclMatchIp(&ae->data, ia->in_addrs[k]))
		    return 1;
	    }
	    return 0;
	} else if (checklist->state[ACL_DST_IP] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		ae->name, r->host);
	    checklist->state[ACL_DST_IP] = ACL_LOOKUP_NEEDED;
	    return 0;
	} else {
	    return aclMatchIp(&ae->data, no_addr);
	}
	/* NOTREACHED */
    case ACL_DST_DOMAIN:
	if ((ia = ipcacheCheckNumeric(r->host)) == NULL)
	    return aclMatchDomainList(&ae->data, r->host);
	fqdn = fqdncache_gethostbyaddr(ia->in_addrs[0], FQDN_LOOKUP_IF_MISS);
	if (fqdn)
	    return aclMatchDomainList(&ae->data, fqdn);
	if (checklist->state[ACL_DST_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		ae->name, inet_ntoa(ia->in_addrs[0]));
	    checklist->state[ACL_DST_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchDomainList(&ae->data, "none");
	/* NOTREACHED */
    case ACL_SRC_DOMAIN:
	fqdn = fqdncache_gethostbyaddr(checklist->src_addr, FQDN_LOOKUP_IF_MISS);
	if (fqdn) {
	    return aclMatchDomainList(&ae->data, fqdn);
	} else if (checklist->state[ACL_SRC_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		ae->name, inet_ntoa(checklist->src_addr));
	    checklist->state[ACL_SRC_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchDomainList(&ae->data, "none");
	/* NOTREACHED */
    case ACL_DST_DOM_REGEX:
	if ((ia = ipcacheCheckNumeric(r->host)) == NULL)
	    return aclMatchRegex((relist *)ae->data, r->host);
	fqdn = fqdncache_gethostbyaddr(ia->in_addrs[0], FQDN_LOOKUP_IF_MISS);
	if (fqdn)
	    return aclMatchRegex((relist *)ae->data, fqdn);
	if (checklist->state[ACL_DST_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		ae->name, inet_ntoa(ia->in_addrs[0]));
	    checklist->state[ACL_DST_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchRegex((relist *)ae->data, "none");
	/* NOTREACHED */
    case ACL_SRC_DOM_REGEX:
	fqdn = fqdncache_gethostbyaddr(checklist->src_addr, FQDN_LOOKUP_IF_MISS);
	if (fqdn) {
	    return aclMatchRegex((relist *)ae->data, fqdn);
	} else if (checklist->state[ACL_SRC_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		ae->name, inet_ntoa(checklist->src_addr));
	    checklist->state[ACL_SRC_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchRegex((relist *)ae->data, "none");
	/* NOTREACHED */
    case ACL_TIME:
	return aclMatchTime((acl_time_data *)ae->data, squid_curtime);
	/* NOTREACHED */
    case ACL_URLPATH_REGEX:
	esc_buf = xstrdup(r->urlpath.buf());
	rfc1738_unescape(esc_buf);
	k = aclMatchRegex((relist *)ae->data, esc_buf);
	safe_free(esc_buf);
	return k;
	/* NOTREACHED */
    case ACL_URL_REGEX:
	esc_buf = xstrdup(urlCanonical(r));
	rfc1738_unescape(esc_buf);
	k = aclMatchRegex((relist *)ae->data, esc_buf);
	safe_free(esc_buf);
	return k;
	/* NOTREACHED */
    case ACL_MAXCONN:
	k = clientdbEstablished(checklist->src_addr, 0);
	return ((k > ((intlist *) ae->data)->i) ? 1 : 0);
	/* NOTREACHED */
    case ACL_URL_PORT:
	return aclMatchIntegerRange((intrange *)ae->data, (int) r->port);
	/* NOTREACHED */
    case ACL_MY_PORT:
	return aclMatchIntegerRange((intrange *)ae->data, (int) checklist->my_port);
	/* NOTREACHED */
#if USE_IDENT
    case ACL_IDENT:
	if (checklist->rfc931[0]) {
	    return aclMatchUser(ae->data, checklist->rfc931);
	} else {
	    checklist->state[ACL_IDENT] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	/* NOTREACHED */
    case ACL_IDENT_REGEX:
	if (checklist->rfc931[0]) {
	    return aclMatchRegex((relist *)ae->data, checklist->rfc931);
	} else {
	    checklist->state[ACL_IDENT] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	/* NOTREACHED */
#endif
    case ACL_PROTO:
	return aclMatchInteger((intlist *)ae->data, r->protocol);
	/* NOTREACHED */
    case ACL_METHOD:
	return aclMatchInteger((intlist *)ae->data, r->method);
	/* NOTREACHED */
    case ACL_BROWSER:
	browser = httpHeaderGetStr(&checklist->request->header, HDR_USER_AGENT);
	if (NULL == browser)
	    return 0;
	return aclMatchRegex((relist *)ae->data, browser);
	/* NOTREACHED */
    case ACL_REFERER_REGEX:
	header = httpHeaderGetStr(&checklist->request->header, HDR_REFERER);
	if (NULL == header)
	    return 0;
	return aclMatchRegex((relist *)ae->data, header);
	/* NOTREACHED */
    case ACL_PROXY_AUTH:
    case ACL_PROXY_AUTH_REGEX:
	if ((ti = aclAuthenticated(checklist)) != 1)
	    return ti;
	ti = aclMatchProxyAuth(ae->data, checklist->auth_user_request,
	    checklist, ae->type);
	checklist->auth_user_request = NULL;
	return ti;
	/* NOTREACHED */
    case ACL_MAX_USER_IP:
	if ((ti = aclAuthenticated(checklist)) != 1)
	    return ti;
	ti = aclMatchUserMaxIP(ae->data, checklist->auth_user_request,
	    checklist->src_addr);
	checklist->auth_user_request = NULL;
	return ti;
	/* NOTREACHED */
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
	return aclMatchWordList((wordlist *)ae->data, checklist->snmp_community);
	/* NOTREACHED */
#endif
    case ACL_SRC_ASN:
	return asnMatchIp(ae->data, checklist->src_addr);
	/* NOTREACHED */
    case ACL_DST_ASN:
	ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
	if (ia) {
	    for (k = 0; k < (int) ia->count; k++) {
		if (asnMatchIp(ae->data, ia->in_addrs[k]))
		    return 1;
	    }
	    return 0;
	} else if (checklist->state[ACL_DST_ASN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("asnMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		ae->name, r->host);
	    checklist->state[ACL_DST_ASN] = ACL_LOOKUP_NEEDED;
	} else {
	    return asnMatchIp(ae->data, no_addr);
	}
	return 0;
	/* NOTREACHED */
#if USE_ARP_ACL
    case ACL_SRC_ARP:
	return aclMatchArp(&ae->data, checklist->src_addr);
	/* NOTREACHED */
#endif
    case ACL_REQ_MIME_TYPE:
	header = httpHeaderGetStr(&checklist->request->header,
	    HDR_CONTENT_TYPE);
	if (NULL == header)
	    header = "";
	return aclMatchRegex((relist *)ae->data, header);
	/* NOTREACHED */
    case ACL_REP_MIME_TYPE:
	if (!checklist->reply)
	    return 0;
	header = httpHeaderGetStr(&checklist->reply->header, HDR_CONTENT_TYPE);
	if (NULL == header)
	    header = "";
	return aclMatchRegex((relist *)ae->data, header);
	/* NOTREACHED */
    case ACL_EXTERNAL:
	return aclMatchExternal(ae->data, checklist);
	/* NOTREACHED */
#if USE_SSL
    case ACL_USER_CERT:
	return aclMatchUserCert(ae->data, checklist);
	/* NOTREACHED */
    case ACL_CA_CERT:
	return aclMatchCACert(ae->data, checklist);
	/* NOTREACHED */
#endif
    case ACL_NONE:
    case ACL_ENUM_MAX:
	break;
    }
    debug(28, 0) ("aclMatchAcl: '%s' has bad type %d\n",
	ae->name, ae->type);
    return 0;
}

int
aclMatchAclList(const acl_list * list, ACLChecklist * checklist)
{
    PROF_start(aclMatchAclList);
    while (list) {
	AclMatchedName = list->_acl->name;
	debug(28, 3) ("aclMatchAclList: checking %s%s\n",
	    list->op ? null_string : "!", list->_acl->name);
	if (aclMatchAcl(list->_acl, checklist) != list->op) {
	    debug(28, 3) ("aclMatchAclList: returning 0\n");
	    PROF_stop(aclMatchAclList);
	    return 0;
	}
	list = list->next;
    }
    debug(28, 3) ("aclMatchAclList: returning 1\n");
    PROF_stop(aclMatchAclList);
    return 1;
}

static void
aclCheckCleanup(ACLChecklist * checklist)
{
    /* Cleanup temporary stuff used by the ACL checking */
    if (checklist->extacl_entry) {
	cbdataReferenceDone(checklist->extacl_entry);
    }
}

/* Warning: do not cbdata lock checklist here - it 
 * may be static or on the stack
 */

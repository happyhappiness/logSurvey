    case ACL_URL_PORT:
    case ACL_URL_REGEX:
	/* These ACL types require checklist->request */
	return true;
    default:
	return false;
    }
}

int
ACL::checklistMatches(ACLChecklist *checklist)
{
    if (NULL == checklist->request && requiresRequest()) {
	debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
		      " HTTP request -- access denied.\n", name);
	return 0;
    }

    debug(28, 3) ("aclMatchAcl: checking '%s'\n", cfgline);
    return match(checklist);
}

int
ACL::match(ACLChecklist * checklist)
{
    request_t *r = checklist->request;
    const ipcache_addrs *ia = NULL;
    const char *fqdn = NULL;
    char *esc_buf;
    const char *header;
    const char *browser;
    int k, ti;

    switch (aclType()) {
    case ACL_DST_DOMAIN:
	if ((ia = ipcacheCheckNumeric(r->host)) == NULL)
	    return aclMatchDomainList(&data, r->host);
	fqdn = fqdncache_gethostbyaddr(ia->in_addrs[0], FQDN_LOOKUP_IF_MISS);
	if (fqdn)
	    return aclMatchDomainList(&data, fqdn);
	if (checklist->state[ACL_DST_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		name, inet_ntoa(ia->in_addrs[0]));
	    checklist->state[ACL_DST_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchDomainList(&data, "none");
	/* NOTREACHED */
    case ACL_SRC_DOMAIN:
	fqdn = fqdncache_gethostbyaddr(checklist->src_addr, FQDN_LOOKUP_IF_MISS);
	if (fqdn) {
	    return aclMatchDomainList(&data, fqdn);
	} else if (checklist->state[ACL_SRC_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		name, inet_ntoa(checklist->src_addr));
	    checklist->state[ACL_SRC_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchDomainList(&data, "none");
	/* NOTREACHED */
    case ACL_DST_DOM_REGEX:
	if ((ia = ipcacheCheckNumeric(r->host)) == NULL)
	    return aclMatchRegex((relist *)data, r->host);
	fqdn = fqdncache_gethostbyaddr(ia->in_addrs[0], FQDN_LOOKUP_IF_MISS);
	if (fqdn)
	    return aclMatchRegex((relist *)data, fqdn);
	if (checklist->state[ACL_DST_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		name, inet_ntoa(ia->in_addrs[0]));
	    checklist->state[ACL_DST_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchRegex((relist *)data, "none");
	/* NOTREACHED */
    case ACL_SRC_DOM_REGEX:
	fqdn = fqdncache_gethostbyaddr(checklist->src_addr, FQDN_LOOKUP_IF_MISS);
	if (fqdn) {
	    return aclMatchRegex((relist *)data, fqdn);
	} else if (checklist->state[ACL_SRC_DOMAIN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		name, inet_ntoa(checklist->src_addr));
	    checklist->state[ACL_SRC_DOMAIN] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	return aclMatchRegex((relist *)data, "none");
	/* NOTREACHED */
    case ACL_TIME:
	return aclMatchTime((acl_time_data *)data, squid_curtime);
	/* NOTREACHED */
    case ACL_URLPATH_REGEX:
	esc_buf = xstrdup(r->urlpath.buf());
	rfc1738_unescape(esc_buf);
	k = aclMatchRegex((relist *)data, esc_buf);
	safe_free(esc_buf);
	return k;
	/* NOTREACHED */
    case ACL_URL_REGEX:
	esc_buf = xstrdup(urlCanonical(r));
	rfc1738_unescape(esc_buf);
	k = aclMatchRegex((relist *)data, esc_buf);
	safe_free(esc_buf);
	return k;
	/* NOTREACHED */
    case ACL_MAXCONN:
	k = clientdbEstablished(checklist->src_addr, 0);
	return ((k > ((intlist *) data)->i) ? 1 : 0);
	/* NOTREACHED */
    case ACL_URL_PORT:
	return aclMatchIntegerRange((intrange *)data, (int) r->port);
	/* NOTREACHED */
    case ACL_MY_PORT:
	return aclMatchIntegerRange((intrange *)data, (int) checklist->my_port);
	/* NOTREACHED */
#if USE_IDENT
    case ACL_IDENT_REGEX:
	if (checklist->rfc931[0]) {
	    return aclMatchRegex((relist *)data, checklist->rfc931);
	} else {
	    checklist->state[ACL_IDENT] = ACL_LOOKUP_NEEDED;
	    return 0;
	}
	/* NOTREACHED */
#endif
    case ACL_PROTO:
	return aclMatchInteger((intlist *)data, r->protocol);
	/* NOTREACHED */
    case ACL_METHOD:
	return aclMatchInteger((intlist *)data, r->method);
	/* NOTREACHED */
    case ACL_BROWSER:
	browser = httpHeaderGetStr(&checklist->request->header, HDR_USER_AGENT);
	if (NULL == browser)
	    return 0;
	return aclMatchRegex((relist *)data, browser);
	/* NOTREACHED */
    case ACL_REFERER_REGEX:
	header = httpHeaderGetStr(&checklist->request->header, HDR_REFERER);
	if (NULL == header)
	    return 0;
	return aclMatchRegex((relist *)data, header);
	/* NOTREACHED */
    case ACL_PROXY_AUTH_REGEX:
	if ((ti = aclAuthenticated(checklist)) != 1)
	    return ti;
	ti = aclMatchProxyAuth(data, checklist->auth_user_request,
	    checklist, aclType());
	checklist->auth_user_request = NULL;
	return ti;
	/* NOTREACHED */
    case ACL_MAX_USER_IP:
	if ((ti = aclAuthenticated(checklist)) != 1)
	    return ti;
	ti = aclMatchUserMaxIP(data, checklist->auth_user_request,
	    checklist->src_addr);
	checklist->auth_user_request = NULL;
	return ti;
	/* NOTREACHED */
#if SQUID_SNMP
    case ACL_SNMP_COMMUNITY:
	return aclMatchWordList((wordlist *)data, checklist->snmp_community);
	/* NOTREACHED */
#endif
    case ACL_SRC_ASN:
	return asnMatchIp(data, checklist->src_addr);
	/* NOTREACHED */
    case ACL_DST_ASN:
	ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
	if (ia) {
	    for (k = 0; k < (int) ia->count; k++) {
		if (asnMatchIp(data, ia->in_addrs[k]))
		    return 1;
	    }
	    return 0;
	} else if (checklist->state[ACL_DST_ASN] == ACL_LOOKUP_NONE) {
	    debug(28, 3) ("asnMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		name, r->host);
	    checklist->state[ACL_DST_ASN] = ACL_LOOKUP_NEEDED;
	} else {
	    return asnMatchIp(data, no_addr);
	}
	return 0;
	/* NOTREACHED */
#if USE_ARP_ACL
    case ACL_SRC_ARP:
	return aclMatchArp(&data, checklist->src_addr);
	/* NOTREACHED */
#endif
    case ACL_REQ_MIME_TYPE:
	header = httpHeaderGetStr(&checklist->request->header,
	    HDR_CONTENT_TYPE);
	if (NULL == header)
	    header = "";
	return aclMatchRegex((relist *)data, header);
	/* NOTREACHED */
    case ACL_REP_MIME_TYPE:
	if (!checklist->reply)
	    return 0;
	header = httpHeaderGetStr(&checklist->reply->header, HDR_CONTENT_TYPE);
	if (NULL == header)
	    header = "";
	return aclMatchRegex((relist *)data, header);
	/* NOTREACHED */
    case ACL_EXTERNAL:
	return aclMatchExternal(data, checklist);
	/* NOTREACHED */
#if USE_SSL
    case ACL_USER_CERT:
	return aclMatchUserCert(data, checklist);
	/* NOTREACHED */
    case ACL_CA_CERT:
	return aclMatchCACert(data, checklist);
	/* NOTREACHED */
#endif
    case ACL_NONE:
    case ACL_ENUM_MAX:
	break;
#if USE_IDENT
    case ACL_IDENT:
#endif
    case ACL_DERIVED:
    case ACL_PROXY_AUTH:
	fatal ("overridden");
    }
    debug(28, 0) ("aclMatchAcl: '%s' has bad type %d\n",
	name, aclType());
    return 0;
}

bool
ACLList::matches (ACLChecklist *checklist) const
{
    assert (_acl);
    AclMatchedName = _acl->name;
    debug(28, 3) ("ACLList::matches: checking %s%s\n",
		  op ? null_string : "!", _acl->name);
    if (_acl->checklistMatches(checklist) != op) {
	return false;
    }
    return true;
}

int
ACLChecklist::matchAclList(const acl_list * head)
{
    PROF_start(aclMatchAclList);
    const acl_list *node = head;
    while (node) {
	if (!node->matches(this)) {
	    debug(28, 3) ("aclmatchAclList: returning 0 (AND list entry failed to match)\n");
	    PROF_stop(aclMatchAclList);
	    return 0;
	}
	node = node->next;
    }
    debug(28, 3) ("aclmatchAclList: returning 1 (AND list satisfied)\n");
    PROF_stop(aclMatchAclList);
    return 1;
}

/* Warning: do not cbdata lock checklist here - it 
 * may be static or on the stack
 */
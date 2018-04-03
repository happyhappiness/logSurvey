     int po;
     char *r;
{
    struct hostent *hp = NULL;
    struct in_addr dst;
    int k;
    if (!acl)
	return 0;
    debug(28, 3, "aclMatchAcl: checking '%s'\n", acl->cfgline);
    switch (acl->type) {
    case ACL_SRC_IP:
	return aclMatchIp(acl->data, c);
	/* NOTREACHED */
    case ACL_DST_IP:
	if ((hp = ipcache_gethostbyname(h, IP_LOOKUP_IF_MISS)) == NULL) {
	    debug(28, 3, "aclMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
		acl->name, h);
	    return 0;		/* cant check, return no match */
	}
	for (k = 0; hp->h_addr_list[k]; k++) {
	    xmemcpy(&dst.s_addr, hp->h_addr_list[k], hp->h_length);
	    if (aclMatchIp(acl->data, dst))
		return 1;
	}
	return 0;
	/* NOTREACHED */
    case ACL_DST_DOMAIN:
	/* XXX This probably needs to use matchDomainName() */
	return aclMatchEndOfWord(acl->data, h);
	/* NOTREACHED */
    case ACL_TIME:
	return aclMatchTime(acl->data, squid_curtime);
	/* NOTREACHED */
    case ACL_URL_REGEX:
	return aclMatchRegex(acl->data, r);
	/* NOTREACHED */
    case ACL_URL_PORT:
	return aclMatchInteger(acl->data, po);
	/* NOTREACHED */
    case ACL_USER:
	debug(28, 0, "aclMatchAcl: ACL_USER unimplemented\n");
	return 0;
	/* NOTREACHED */
    case ACL_PROTO:
	return aclMatchInteger(acl->data, pr);
	/* NOTREACHED */
    case ACL_METHOD:
	return aclMatchInteger(acl->data, m);
	/* NOTREACHED */
    case ACL_NONE:
    default:
	debug(28, 0, "aclMatchAcl: '%s' has bad type %d\n",
	    acl->name, acl->type);
	return 0;
    }
    /* NOTREACHED */
}

static int aclMatchAclList(list, c, m, pr, h, po, r)

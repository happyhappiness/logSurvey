     int po;
     char *r;
{
    if (!acl)
	return 0;
    debug(28, 3, "aclMatchAcl: checking '%s'\n", acl->cfgline);
    switch (acl->type) {
    case ACL_SRC_IP:
	return aclMatchIp(acl->data, c);
	/* NOTREACHED */
	break;
    case ACL_DST_DOMAIN:
	return aclMatchWord(acl->data, h);
	/* NOTREACHED */
	break;
    case ACL_TIME:
	return aclMatchTime(acl->data, squid_curtime);
	/* NOTREACHED */
	break;
    case ACL_URL_REGEX:
	return aclMatchRegex(acl->data, r);
	/* NOTREACHED */
	break;
    case ACL_URL_PORT:
	return aclMatchInteger(acl->data, po);
	/* NOTREACHED */
	break;
    case ACL_USER:
	debug(28, 0, "aclMatchAcl: ACL_USER unimplemented\n");
	return 0;
	/* NOTREACHED */
	break;
    case ACL_PROTO:
	return aclMatchInteger(acl->data, pr);
	/* NOTREACHED */
	break;
    case ACL_METHOD:
	return aclMatchInteger(acl->data, m);
	/* NOTREACHED */
	break;
    case ACL_NONE:
    default:
	debug(28, 0, "aclMatchAcl: '%s' has bad type %d\n",
	    acl->name, acl->type);
	return 0;
    }
    fatal_dump("aclMatchAcl: This should never happen.");
    return 0;
}

static int aclMatchAclList(list, c, m, pr, h, po, r)

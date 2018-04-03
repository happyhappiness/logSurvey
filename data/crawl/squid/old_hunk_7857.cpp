    return 1;
}

int aclCheck(cli_addr, proto, host, port, request)
     struct in_addr cli_addr;
     protocol_t proto;
     char *host;
     int port;
     char *request;
{
    struct _acl_access *A = NULL;
    int allow = 0;

    debug(28, 1, "aclCheck: cli_addr=%s\n", inet_ntoa(cli_addr));
    debug(28, 1, "aclCheck: proto=%d\n", proto);
    debug(28, 1, "aclCheck: host=%s\n", host);
    debug(28, 1, "aclCheck: port=%d\n", port);
    debug(28, 1, "aclCheck: request=%s\n", request);

    for (A = AccessList; A; A = A->next) {
	debug(28, 1, "aclCheck: checking '%s'\n", A->cfgline);
	allow = A->allow;
	if (aclMatchAclList(A->acl_list, cli_addr, proto, host, port, request)) {
	    debug(28, 1, "aclCheck: match found, returning %d\n", allow);
	    return allow;
	}
    }
    return !allow;
}

    return 1;
}

int aclCheck(A, cli_addr, method, proto, host, port, request)
     struct _acl_access *A;
     struct in_addr cli_addr;
     method_t method;
     protocol_t proto;
     char *host;
     int port;
     char *request;
{
    int allow = 0;

    debug(28, 1, "aclCheck: cli_addr=%s\n", inet_ntoa(cli_addr));
    debug(28, 1, "aclCheck: method=%d\n", method);
    debug(28, 1, "aclCheck: proto=%d\n", proto);
    debug(28, 1, "aclCheck: host=%s\n", host);
    debug(28, 1, "aclCheck: port=%d\n", port);
    debug(28, 1, "aclCheck: request=%s\n", request);

    while (A) {
	debug(28, 1, "aclCheck: checking '%s'\n", A->cfgline);
	allow = A->allow;
	if (aclMatchAclList(A->acl_list, cli_addr, method, proto, host, port, request)) {
	    debug(28, 1, "aclCheck: match found, returning %d\n", allow);
	    return allow;
	}
	A = A->next;
    }
    return !allow;
}

static void aclDestroyIpList(data)
	struct _acl_ip_data *data;
{
	struct _acl_ip_data *next;
	for (; data; data=next) {
		next = data->next;
		safe_free(data);
	}
}

static void aclDestroyTimeList(data)
	struct _acl_time_data *data;
{
	struct _acl_time_data *next;
	for (; data; data=next) {
		next = data->next;
		safe_free(data);
	}
}

static void aclDestroyRegexList(data)
	struct _relist *data;
{
	struct _relist *next;
	for (; data; data=next) {
		next = data->next;
		regfree(&data->regex);
		safe_free(data->pattern);
		safe_free(data);
	}
}

void aclDestroyAcls() {
	struct _acl *a = NULL;
	struct _acl *next = NULL;
	for (a=AclList; a; a=next) {
		next = a->next;
		debug(28,1,"aclDestroyAcls: '%s'\n", a->cfgline);
		switch(a->type) {
    		case ACL_SRC_IP:
			aclDestroyIpList(a->data);
			break;
    		case ACL_DST_DOMAIN:
    		case ACL_USER:
			wordlistDestroy((wordlist **) &a->data);
			break;
    		case ACL_TIME:
			aclDestroyTimeList(a->data);
			break;
    		case ACL_URL_REGEX:
			aclDestroyRegexList(a->data);
			break;
    		case ACL_URL_PORT:
    		case ACL_PROTO:
    		case ACL_METHOD:
			intlistDestroy((intlist **) &a->data);
			break;
		case ACL_NONE:
		default:
			fatal_dump("aclDestroyAcls: Found ACL_NONE?");
			break;
		}
		safe_free(a->cfgline);
		safe_free(a);
	}
	AclList = NULL;
        AclListTail = &AclList;
}

void aclDestroyAclList(list)
	struct _acl_list *list;
{
	struct _acl_list *next = NULL;
	for (; list ; list=next) {
		next = list->next;
		safe_free(list);
	}
}

void aclDestroyAccessList(list)
	struct _acl_access **list;
{
	struct _acl_access *l = NULL;
	struct _acl_access *next = NULL;
	for (l=*list; l ; l=next) {
		debug(28,1,"aclDestroyAccessList: '%s'\n", l->cfgline);
		next = l->next;
		aclDestroyAclList(l->acl_list);
		l->acl_list = NULL;
		safe_free(l->cfgline);
		safe_free(l);
	}
	*list = NULL;
}


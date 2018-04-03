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


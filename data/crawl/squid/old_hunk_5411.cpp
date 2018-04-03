    checklist->check();
}

static void
aclLookupProxyAuthDone(void *data, char *result)
{
    ACLChecklist *checklist = (ACLChecklist *)data;
    checklist->state[ACL_PROXY_AUTH] = ACL_LOOKUP_DONE;
    if (result != NULL)
	fatal("AclLookupProxyAuthDone: Old code floating around somewhere.\nMake clean and if that doesn't work, report a bug to the squid developers.\n");
    if (!authenticateValidateUser(checklist->auth_user_request) || checklist->conn() == NULL) {
	/* credentials could not be checked either way
	 * restart the whole process */
	/* OR the connection was closed, there's no way to continue */
	authenticateAuthUserRequestUnlock(checklist->auth_user_request);
	if (checklist->conn()) {
	    checklist->conn()->auth_user_request = NULL;
	    checklist->conn()->auth_type = AUTH_BROKEN;
	}
	checklist->auth_user_request = NULL;
    }
    checklist->asyncInProgress(false);
    checklist->check();
}

static void
aclLookupExternalDone(void *data, void *result)
{
    ACLChecklist *checklist = (ACLChecklist *)data;
    checklist->state[ACL_EXTERNAL] = ACL_LOOKUP_DONE;
    checklist->extacl_entry = cbdataReference((external_acl_entry *)result);
    checklist->asyncInProgress(false);
    checklist->check();
}

CBDATA_CLASS_INIT(ACLChecklist);

void *
ACLChecklist::operator new (size_t size)
{
    assert (size == sizeof(ACLChecklist));
    CBDATA_INIT_TYPE(ACLChecklist);
    ACLChecklist *result = cbdataAlloc(ACLChecklist);
    /* Mark result as being owned - we want the refcounter to do the delete
     * call */
    cbdataReference(result);
    return result;
}
 
void
ACLChecklist::operator delete (void *address)
{
    ACLChecklist *t = static_cast<ACLChecklist *>(address);
    cbdataFree(address);
    /* And allow the memory to be freed */
    cbdataReferenceDone (t);
}

void
ACLChecklist::deleteSelf() const
{
    delete this;
}

ACLChecklist::ACLChecklist() : accessList (NULL), my_port (0), request (NULL),
  reply (NULL),
  auth_user_request (NULL)
#if SQUID_SNMP
    ,snmp_community(NULL)
#endif
  , callback (NULL),
  callback_data (NULL),
  extacl_entry (NULL),
  conn_(NULL),
  async_(false),
  finished_(false),
  allow_(ACCESS_DENIED),
  state_(NullState::Instance())
{
    memset (&src_addr, '\0', sizeof (struct in_addr));
    memset (&dst_addr, '\0', sizeof (struct in_addr));
    memset (&my_addr, '\0', sizeof (struct in_addr));
    rfc931[0] = '\0';
    memset (&state, '\0', sizeof (state));
}

ACLChecklist::~ACLChecklist()
{
    assert (!asyncInProgress());
    if (extacl_entry)
	cbdataReferenceDone(extacl_entry);
    if (request)
	requestUnlink(request);
    request = NULL;
    cbdataReferenceDone(conn_);
    cbdataReferenceDone(accessList);
}

ConnStateData *
ACLChecklist::conn()
{
    return  conn_;
}

void
ACLChecklist::conn(ConnStateData *aConn)
{
    assert (conn() == NULL);
    conn_ = aConn;
}

/*
 * Any ACLChecklist created by aclChecklistCreate() must eventually be
 * freed by ACLChecklist::operator delete().  There are two common cases:

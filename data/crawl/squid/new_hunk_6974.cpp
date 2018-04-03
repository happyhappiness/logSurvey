    int do_ping = 1;
    const struct _acl_list *a = NULL;
    aclCheck_t checklist;
    assert(request != NULL);
    if (EBIT_TEST(request->flags, REQ_NOCACHE))
	if (neighborType(p, request) == PEER_SIBLING)
	    return 0;

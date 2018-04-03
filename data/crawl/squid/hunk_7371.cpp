     const struct _acl_list *a = NULL;
     aclCheck_t checklist;
 
+    if (request == NULL)
+	fatal_dump("peerAllowedToUse: NULL request");
     if (BIT_TEST(request->flags, REQ_NOCACHE))
 	if (neighborType(e, request) == PEER_SIBLING)
 	    return 0;

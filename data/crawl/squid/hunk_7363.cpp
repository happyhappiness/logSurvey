     int do_ping = 1;
     const struct _acl_list *a = NULL;
     aclCheck_t checklist;
-
     if (request == NULL)
 	fatal_dump("peerAllowedToUse: NULL request");
     if (BIT_TEST(request->flags, REQ_NOCACHE))

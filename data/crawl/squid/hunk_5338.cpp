     }
 }
 
+bool
+ACL::requiresReply() const
+{
+    return false;
+}
 
-CBDATA_TYPE(acl_user_ip_data);
-
-void
-aclParseUserMaxIP(void *data)
+bool
+ACL::requiresRequest() const
 {
-    acl_user_ip_data **acldata = (acl_user_ip_data **)data;
-    char *t = NULL;
-    CBDATA_INIT_TYPE(acl_user_ip_data);
+    return false;
+}
 
-    if (*acldata) {
-        debug(28, 1) ("Attempting to alter already set User max IP acl\n");
-        return;
+int
+ACL::checklistMatches(ACLChecklist *checklist)
+{
+    if (NULL == checklist->request && requiresRequest()) {
+        debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
+                      " HTTP request -- not matching.\n", name);
+        return 0;
     }
 
-    *acldata = cbdataAlloc(acl_user_ip_data);
-    t = strtokFile();
-
-    if (!t)
-        goto error;
-
-    debug(28, 5) ("aclParseUserMaxIP: First token is %s\n", t);
-
-    if (strcmp("-s", t) == 0) {
-        debug(28, 5) ("aclParseUserMaxIP: Going strict\n");
-        (*acldata)->flags.strict = 1;
-        t = strtokFile();
-
-        if (!t)
-            goto error;
+    if (NULL == checklist->reply && requiresReply()) {
+        debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
+                      " HTTP reply -- not matching.\n", name);
+        return 0;
     }
 
-    (*acldata)->max = atoi(t);
-    debug(28, 5) ("aclParseUserMaxIP: Max IP address's %d\n", (int) (*acldata)->max);
-    return;
-
-error:
-    fatal("aclParseUserMaxIP: Malformed ACL %d\n");
+    debug(28, 3) ("aclMatchAcl: checking '%s'\n", cfgline);
+    return match(checklist);
 }
 
-void
-aclDestroyUserMaxIP(void *data)
+bool
+ACLList::matches (ACLChecklist *checklist) const
 {
-    acl_user_ip_data **acldata = (acl_user_ip_data **)data;
+    assert (_acl);
+    AclMatchedName = _acl->name;
+    debug(28, 3) ("ACLList::matches: checking %s%s\n",
+                  op ? null_string : "!", _acl->name);
 
-    if (*acldata)
-        cbdataFree(*acldata);
+    if (_acl->checklistMatches(checklist) != op) {
+        return false;
+    }
 
-    *acldata = NULL;
+    return true;
 }
 
-wordlist *
-aclDumpUserMaxIP(void *data)
+/* Warning: do not cbdata lock checklist here - it
+ * may be static or on the stack
+ */
+int
+aclCheckFast(const acl_access * A, ACLChecklist * checklist)
 {
-    acl_user_ip_data *acldata = (acl_user_ip_data *)data;
-    wordlist *W = NULL;
-    char buf[128];
-
-    if (acldata->flags.strict)
-        wordlistAdd(&W, "-s");
+    allow_t allow = ACCESS_DENIED;
+    PROF_start(aclCheckFast);
+    debug(28, 5) ("aclCheckFast: list: %p\n", A);
 
-    snprintf(buf, sizeof(buf), "%lu", (unsigned long int) acldata->max);
+    while (A) {
+        allow = A->allow;
+        checklist->matchAclList(A->aclList, true);
 
-    wordlistAdd(&W, buf);
-
-    return W;
-}
-
-/*
- * aclMatchUserMaxIP - check for users logging in from multiple IP's 
- * 0 : No match
- * 1 : Match 
- */
-int
-aclMatchUserMaxIP(void *data, auth_user_request_t * auth_user_request,
-
-                  struct in_addr src_addr)
-{
-    /*
-     * the logic for flush the ip list when the limit is hit vs keep
-     * it sorted in most recent access order and just drop the oldest
-     * one off is currently undecided
-     */
-    acl_user_ip_data *acldata = (acl_user_ip_data *)data;
-
-    if (authenticateAuthUserRequestIPCount(auth_user_request) <= acldata->max)
-        return 0;
-
-    /* this is a match */
-    if (acldata->flags.strict)
-    {
-        /*
-         * simply deny access - the user name is already associated with
-         * the request 
-         */
-        /* remove _this_ ip, as it is the culprit for going over the limit */
-        authenticateAuthUserRequestRemoveIp(auth_user_request, src_addr);
-        debug(28, 4) ("aclMatchUserMaxIP: Denying access in strict mode\n");
-    } else
-    {
-        /*
-         * non-strict - remove some/all of the cached entries 
-         * ie to allow the user to move machines easily
-         */
-        authenticateAuthUserRequestClearIp(auth_user_request);
-        debug(28, 4) ("aclMatchUserMaxIP: Denying access in non-strict mode - flushing the user ip cache\n");
-    }
-
-    return 1;
-}
-
-static int
-aclMatchInteger(intlist * data, int i)
-{
-    intlist *first, *prev;
-    first = data;
-    prev = NULL;
-
-    while (data) {
-        if (data->i == i) {
-            if (prev != NULL) {
-                /* shift the element just found to the second position
-                 * in the list */
-                prev->next = data->next;
-                data->next = first->next;
-                first->next = data;
-            }
-
-            return 1;
-        }
-
-        prev = data;
-        data = data->next;
-    }
-
-    return 0;
-}
-
-static int
-aclMatchIntegerRange(intrange * data, int i)
-{
-    intrange *first, *prev;
-    first = data;
-    prev = NULL;
-
-    while (data) {
-        if (i < data->i) {
-            (void) 0;
-        } else if (i > data->j) {
-            (void) 0;
-        } else {
-            /* matched */
-
-            if (prev != NULL) {
-                /* shift the element just found to the second position
-                 * in the list */
-                prev->next = data->next;
-                data->next = first->next;
-                first->next = data;
-            }
-
-            return 1;
-        }
-
-        prev = data;
-        data = data->next;
-    }
-
-    return 0;
-}
-
-#if SQUID_SNMP
-static int
-aclMatchWordList(wordlist * w, const char *word)
-{
-    debug(28, 3) ("aclMatchWordList: looking for '%s'\n", word);
-
-    while (w != NULL) {
-        debug(28, 3) ("aclMatchWordList: checking '%s'\n", w->key);
-
-        if (!strcmp(w->key, word))
-            return 1;
-
-        w = w->next;
-    }
-
-    return 0;
-}
-
-#endif
-
-
-bool
-ACL::requiresRequest() const
-{
-    switch (aclType()) {
-
-    case ACL_DST_ASN:
-
-    case ACL_MAX_USER_IP:
-
-    case ACL_METHOD:
-
-    case ACL_PROTO:
-
-    case ACL_REP_MIME_TYPE:
-
-    case ACL_URL_PORT:
-        /* These ACL types require checklist->request */
-        return true;
-
-    default:
-        return false;
-    }
-}
-
-int
-ACL::checklistMatches(ACLChecklist *checklist)
-{
-    if (NULL == checklist->request && requiresRequest()) {
-        debug(28, 1) ("WARNING: '%s' ACL is used but there is no"
-                      " HTTP request -- access denied.\n", name);
-        return 0;
-    }
-
-    debug(28, 3) ("aclMatchAcl: checking '%s'\n", cfgline);
-    return match(checklist);
-}
-
-int
-ACL::match(ACLChecklist * checklist)
-{
-    request_t *r = checklist->request;
-    const ipcache_addrs *ia = NULL;
-    const char *header;
-    int k, ti;
-
-    switch (aclType()) {
-
-    case ACL_MAXCONN:
-        k = clientdbEstablished(checklist->src_addr, 0);
-        return ((k > ((intlist *) data)->i) ? 1 : 0);
-        /* NOTREACHED */
-
-    case ACL_URL_PORT:
-        return aclMatchIntegerRange((intrange *)data, (int) r->port);
-        /* NOTREACHED */
-
-    case ACL_MY_PORT:
-        return aclMatchIntegerRange((intrange *)data, (int) checklist->my_port);
-        /* NOTREACHED */
-
-    case ACL_PROTO:
-        return aclMatchInteger((intlist *)data, r->protocol);
-        /* NOTREACHED */
-
-    case ACL_METHOD:
-        return aclMatchInteger((intlist *)data, r->method);
-        /* NOTREACHED */
-
-    case ACL_MAX_USER_IP:
-
-        if ((ti = checklist->authenticated()) != 1)
-            return ti;
-
-        ti = aclMatchUserMaxIP(data, checklist->auth_user_request,
-                               checklist->src_addr);
-
-        checklist->auth_user_request = NULL;
-
-        return ti;
-
-        /* NOTREACHED */
-#if SQUID_SNMP
-
-    case ACL_SNMP_COMMUNITY:
-        return aclMatchWordList((wordlist *)data, checklist->snmp_community);
-
-        /* NOTREACHED */
-#endif
-
-    case ACL_SRC_ASN:
-        return asnMatchIp(data, checklist->src_addr);
-
-        /* NOTREACHED */
-
-    case ACL_DST_ASN:
-        ia = ipcache_gethostbyname(r->host, IP_LOOKUP_IF_MISS);
-
-        if (ia) {
-            for (k = 0; k < (int) ia->count; k++) {
-                if (asnMatchIp(data, ia->in_addrs[k]))
-                    return 1;
-            }
-
-            return 0;
-        } else if (checklist->state[ACL_DST_ASN] == ACL_LOOKUP_NONE) {
-            debug(28, 3) ("asnMatchAcl: Can't yet compare '%s' ACL for '%s'\n",
-                          name, r->host);
-            checklist->changeState (DestinationIPLookup::Instance());
-        } else {
-            return asnMatchIp(data, no_addr);
-        }
-
-        return 0;
-        /* NOTREACHED */
-#if USE_ARP_ACL
-
-    case ACL_SRC_ARP:
-        return aclMatchArp(&data, checklist->src_addr);
-        /* NOTREACHED */
-#endif
-
-    case ACL_REP_MIME_TYPE:
-
-        if (!checklist->reply)
-            return 0;
-
-        header = httpHeaderGetStr(&checklist->reply->header, HDR_CONTENT_TYPE);
-
-        if (NULL == header)
-            header = "";
-
-        return aclMatchRegex((relist *)data, header);
-
-        /* NOTREACHED */
-
-    case ACL_EXTERNAL:
-        return aclMatchExternal(data, checklist);
-
-        /* NOTREACHED */
-
-    case ACL_NONE:
-
-    case ACL_ENUM_MAX:
-        break;
-
-    case ACL_DERIVED:
-        fatal ("overridden");
-    }
-
-    debug(28, 0) ("aclMatchAcl: '%s' has bad type %d\n",
-                  name, aclType());
-    return 0;
-}
-
-bool
-ACLList::matches (ACLChecklist *checklist) const
-{
-    assert (_acl);
-    AclMatchedName = _acl->name;
-    debug(28, 3) ("ACLList::matches: checking %s%s\n",
-                  op ? null_string : "!", _acl->name);
-
-    if (_acl->checklistMatches(checklist) != op) {
-        return false;
-    }
-
-    return true;
-}
-
-/* Warning: do not cbdata lock checklist here - it
- * may be static or on the stack
- */
-int
-aclCheckFast(const acl_access * A, ACLChecklist * checklist)
-{
-    allow_t allow = ACCESS_DENIED;
-    PROF_start(aclCheckFast);
-    debug(28, 5) ("aclCheckFast: list: %p\n", A);
-
-    while (A) {
-        allow = A->allow;
-
-        if (checklist->matchAclList(A->aclList, true)) {
-            PROF_stop(aclCheckFast);
-            return allow == ACCESS_ALLOWED;
-        }
+        if (checklist->finished()) {
+            PROF_stop(aclCheckFast);
+            return allow == ACCESS_ALLOWED;
+        }
 
         A = A->next;
     }

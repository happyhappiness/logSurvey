     memset(addr, '\0', sizeof(struct in_addr));
 }
 
+CBDATA_TYPE(acl_address);
+
+static void
+dump_acl_address(StoreEntry * entry, const char *name, acl_address * head)
+{
+    acl_address *l;
+    for (l = head; l; l = l->next) {
+	if (l->addr.s_addr != INADDR_ANY)
+	    storeAppendPrintf(entry, "%s %s", name, inet_ntoa(l->addr));
+	else
+	    storeAppendPrintf(entry, "%s autoselect", name);
+	dump_acl_list(entry, l->acl_list);
+	storeAppendPrintf(entry, "\n");
+    }
+}
+
+static void
+freed_acl_address(void *data)
+{
+    acl_address *l = data;
+    aclDestroyAclList(&l->acl_list);
+}
+
+static void
+parse_acl_address(acl_address ** head)
+{
+    acl_address *l;
+    acl_address **tail = head;	/* sane name below */
+    CBDATA_INIT_TYPE_FREECB(acl_address, freed_acl_address);
+    l = cbdataAlloc(acl_address);
+    parse_address(&l->addr);
+    aclParseAclList(&l->acl_list);
+    while (*tail)
+	tail = &(*tail)->next;
+    *tail = l;
+}
+
+static void
+free_acl_address(acl_address ** head)
+{
+    while (*head) {
+	acl_address *l = *head;
+	*head = l->next;
+	cbdataFree(l);
+    }
+}
+
+CBDATA_TYPE(acl_tos);
+
+static void
+dump_acl_tos(StoreEntry * entry, const char *name, acl_tos * head)
+{
+    acl_tos *l;
+    for (l = head; l; l = l->next) {
+	if (l->tos > 0)
+	    storeAppendPrintf(entry, "%s 0x%02X", name, l->tos);
+	else
+	    storeAppendPrintf(entry, "%s none", name);
+	dump_acl_list(entry, l->acl_list);
+	storeAppendPrintf(entry, "\n");
+    }
+}
+
+static void
+freed_acl_tos(void *data)
+{
+    acl_tos *l = data;
+    aclDestroyAclList(&l->acl_list);
+}
+
+static void
+parse_acl_tos(acl_tos ** head)
+{
+    acl_tos *l;
+    acl_tos **tail = head;	/* sane name below */
+    int tos;
+    char junk;
+    char *token = strtok(NULL, w_space);
+    if (!token)
+	self_destruct();
+    if (sscanf(token, "0x%x%c", &tos, &junk) != 1)
+	self_destruct();
+    if (tos < 0 || tos > 255)
+	self_destruct();
+    CBDATA_INIT_TYPE_FREECB(acl_tos, freed_acl_tos);
+    l = cbdataAlloc(acl_tos);
+    l->tos = tos;
+    aclParseAclList(&l->acl_list);
+    while (*tail)
+	tail = &(*tail)->next;
+    *tail = l;
+}
+
+static void
+free_acl_tos(acl_tos ** head)
+{
+    while (*head) {
+	acl_tos *l = *head;
+	*head = l->next;
+	l->next = NULL;
+	cbdataFree(l);
+    }
+}
+
 #if DELAY_POOLS
 
 /* do nothing - free_delay_pool_count is the magic free function.

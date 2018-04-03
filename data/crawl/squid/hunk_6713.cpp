     aclDestroyAcls(acl);
 }
 
+static void
+dump_snmp_access(StoreEntry * entry, const char *name, communityEntry * Head)
+{
+    acl_list *l;
+    communityEntry *cp;
+    acl_access *head;
+ 
+    for (cp = Head; cp; cp = cp->next) {
+	head=cp->acls;
+       while (head != NULL) {
+	for (l = head->acl_list; l != NULL; l = l->next) {
+	    storeAppendPrintf(entry, "%s %s %s %s%s\n",
+		name, cp->name, 
+		head->allow ? "Allow" : "Deny",
+		l->op ? "" : "!",
+		l->acl->name);
+	}
+	head = head->next;
+       }
+    }
+}
+
 static void
 dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
 {

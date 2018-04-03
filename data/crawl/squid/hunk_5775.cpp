 }
 
 static void
-dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
+dump_acl_list(StoreEntry * entry, acl_list * head)
 {
     acl_list *l;
-    while (head != NULL) {
+    for (l = head; l; l = l->next) {
+	storeAppendPrintf(entry, " %s%s",
+	    l->op ? null_string : "!",
+	    l->acl->name);
+    }
+}
+
+static void
+dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
+{
+    acl_access *l;
+    for (l = head; l; l = l->next) {
 	storeAppendPrintf(entry, "%s %s",
 	    name,
-	    head->allow ? "Allow" : "Deny");
-	for (l = head->acl_list; l != NULL; l = l->next) {
-	    storeAppendPrintf(entry, " %s%s",
-		l->op ? null_string : "!",
-		l->acl->name);
-	}
+	    l->allow ? "Allow" : "Deny");
+	dump_acl_list(entry, l->acl_list);
 	storeAppendPrintf(entry, "\n");
-	head = head->next;
     }
 }
 

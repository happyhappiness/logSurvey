 void
 dump_acl_list(StoreEntry * entry, ACLList * head)
 {
-    ACLList *l;
-
-    for (l = head; l; l = l->next) {
-        storeAppendPrintf(entry, " %s%s",
-                          l->op ? null_string : "!",
-                          l->_acl->name);
-    }
+    wordlist *values = head->dump();
+    dump_wordlist(entry, values);
+    wordlistDestroy(&values);
 }
 
 void
 dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
 {
-    acl_access *l;
-
-    for (l = head; l; l = l->next) {
-        storeAppendPrintf(entry, "%s %s",
-                          name,
-                          l->allow ? "Allow" : "Deny");
-        dump_acl_list(entry, l->aclList);
-        storeAppendPrintf(entry, "\n");
-    }
+    wordlist *lines = head->treeDump(name, NULL);
+    dump_wordlist(entry, lines);
+    wordlistDestroy(&lines);
 }
 
 static void
 parse_acl_access(acl_access ** head)
 {
-    aclParseAccessLine(LegacyParser, head);
+    aclParseAccessLine(cfg_directive, LegacyParser, head);
+}
+
+static void
+parse_acl_access(const char *directive, acl_access ** head)
+{
+    aclParseAccessLine(directive, LegacyParser, head);
 }
 
 static void

 	debug(49, 5) ("snmp: unknown directive %s\n", tokens[0]);
 }
 
+static void
+dump_snmp_conf(StoreEntry * entry, const char *name, snmpconf * head)
+{
+    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
+}
+
+static void
+free_snmp_conf(snmpconf ** head)
+{
+    snmpconf *t;
+    while ((t = *head) != NULL) {
+	*head = t->next;
+	safe_free(t->line);
+	safe_free(t);
+    }
+}
+#endif
+
 static void
 parse_acl(acl ** acl)
 {

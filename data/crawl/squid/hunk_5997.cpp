     storeAppendPrintf(entry, "%s %s\n", name, s);
 }
 
+static void
+free_removalpolicy(RemovalPolicySettings **settings)
+{
+    if (!*settings)
+	return;
+    free_string(&(*settings)->type);
+    free_wordlist(&(*settings)->args);
+    xfree(*settings);
+    *settings = NULL;
+}
+
+static void
+parse_removalpolicy(RemovalPolicySettings **settings)
+{
+    if (*settings)
+	free_removalpolicy(settings);
+    *settings = xcalloc(1, sizeof(**settings));
+    parse_string(&(*settings)->type);
+    parse_wordlist(&(*settings)->args);
+}
+
+static void
+dump_removalpolicy(StoreEntry * entry, const char *name, RemovalPolicySettings *settings)
+{
+    wordlist *args;
+    storeAppendPrintf(entry, "%s %s", name, settings->type);
+    args = settings->args;
+    while (args) {
+	storeAppendPrintf(entry, " %s", args->key);
+	args = args->next;
+    }
+}
+    
+
 #include "cf_parser.c"
 
 peer_t

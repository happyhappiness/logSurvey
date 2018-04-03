 }
 
 static void
-dump_removalpolicy(StoreEntry * entry, const char *name, RemovalPolicySettings *settings)
+dump_removalpolicy(StoreEntry * entry, const char *name, RemovalPolicySettings * settings)
 {
     wordlist *args;
     storeAppendPrintf(entry, "%s %s", name, settings->type);

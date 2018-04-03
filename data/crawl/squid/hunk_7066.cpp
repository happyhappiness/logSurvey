 }
 
 static void
-dump_string(StoreEntry *entry, const char *name, char *var)
+dump_string(StoreEntry * entry, const char *name, char *var)
 {
     if (var != NULL)
-        storeAppendPrintf(entry, "%s %s\n", name, var);
+	storeAppendPrintf(entry, "%s %s\n", name, var);
 }
 
 static void

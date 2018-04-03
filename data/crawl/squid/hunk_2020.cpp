 }
 
 static
-void header_mangler_clean(header_mangler &m)
+void header_mangler_clean(headerMangler &m)
 {
     aclDestroyAccessList(&m.access_list);
     safe_free(m.replacement);
 }
 
 static
 void header_mangler_dump_access(StoreEntry * entry, const char *option,
-                                const header_mangler &m, const char *name)
+                                const headerMangler &m, const char *name)
 {
     if (m.access_list != NULL) {
         storeAppendPrintf(entry, "%s ", option);

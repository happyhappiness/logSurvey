 }
 
 static void
-dump_denyinfo(StoreEntry * entry, const char *name, acl_deny_info_list * var)
+dump_denyinfo(StoreEntry * entry, const char *name, AclDenyInfoList * var)
 {
-    acl_name_list *a;
+    AclNameList *a;
 
     while (var != NULL) {
         storeAppendPrintf(entry, "%s %s", name, var->err_page_name);

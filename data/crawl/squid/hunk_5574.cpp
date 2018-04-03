 	storeAppendPrintf(entry, "%s %s",
 	    name,
 	    l->allow ? "Allow" : "Deny");
-	dump_acl_list(entry, l->acl_list);
+	dump_acl_list(entry, l->aclList);
 	storeAppendPrintf(entry, "\n");
     }
 }

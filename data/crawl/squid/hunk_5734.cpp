 	acl_list *l;
 	acl_access *head = bs->access_list;
 	while (head != NULL) {
-	    storeAppendPrintf(entry, "%s %d %s", name, bs->maxsize,
+	    storeAppendPrintf(entry, "%s %ld %s", name, (long int) bs->maxsize,
 		head->allow ? "Allow" : "Deny");
 	    for (l = head->acl_list; l != NULL; l = l->next) {
 		storeAppendPrintf(entry, " %s%s",

 {
     acl_list *l;
     while (head != NULL) {
-	for (l = head->acl_list; l != NULL; l = l->next) {
-	    storeAppendPrintf(entry, "%s %s %s%s\n",
+	storeAppendPrintf(entry, "%s %s",
 		name,
-		head->allow ? "Allow" : "Deny",
-		l->op ? "" : "!",
+	    head->allow ? "Allow" : "Deny");
+	for (l = head->acl_list; l != NULL; l = l->next) {
+	    storeAppendPrintf(entry, " %s%s",
+		l->op ? null_string : "!",
 		l->acl->name);
 	}
+	storeAppendPrintf(entry, "\n");
 	head = head->next;
     }
 }

     acl_list *l;
     communityEntry *cp;
     acl_access *head;
- 
+
     for (cp = Head; cp; cp = cp->next) {
-	head=cp->acls;
-       while (head != NULL) {
-	for (l = head->acl_list; l != NULL; l = l->next) {
-	    storeAppendPrintf(entry, "%s %s %s %s%s\n",
-		name, cp->name, 
-		head->allow ? "Allow" : "Deny",
-		l->op ? "" : "!",
-		l->acl->name);
+	head = cp->acls;
+	while (head != NULL) {
+	    for (l = head->acl_list; l != NULL; l = l->next) {
+		storeAppendPrintf(entry, "%s %s %s %s%s\n",
+		    name, cp->name,
+		    head->allow ? "Allow" : "Deny",
+		    l->op ? "" : "!",
+		    l->acl->name);
+	    }
+	    head = head->next;
 	}
-	head = head->next;
-       }
     }
 }
 #endif

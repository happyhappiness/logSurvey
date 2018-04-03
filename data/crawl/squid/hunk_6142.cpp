 	fatal("Bad ACL type");
 	break;
     }
+    /*
+     * Clear AclMatchedName from our temporary hack
+    */
+    AclMatchedName = NULL;	/* ugly */
     if (!new_acl)
 	return;
     if (A->data == NULL) {

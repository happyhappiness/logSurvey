 		common = shift_tree_object(head, common, o->subtree_shift);
 	}
 
-	if (sha_eq(common->object.oid.hash, merge->object.oid.hash)) {
+	if (oid_eq(&common->object.oid, &merge->object.oid)) {
 		output(o, 0, _("Already up-to-date!"));
 		*result = head;
 		return 1;

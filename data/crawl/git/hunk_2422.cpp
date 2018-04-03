 		common = shift_tree_object(head, common, o->subtree_shift);
 	}
 
-	if (sha_eq(get_object_hash(common->object), get_object_hash(merge->object))) {
+	if (sha_eq(common->object.oid.hash, merge->object.oid.hash)) {
 		output(o, 0, _("Already up-to-date!"));
 		*result = head;
 		return 1;

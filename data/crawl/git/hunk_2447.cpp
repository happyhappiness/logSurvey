 
 static void new_parent(struct commit *parent, struct commit_list **parents_p)
 {
-	unsigned char *sha1 = parent->object.sha1;
+	struct object_id *oid = &parent->object.oid;
 	struct commit_list *parents;
 	for (parents = *parents_p; parents; parents = parents->next) {
 		if (parents->item == parent) {
-			error("duplicate parent %s ignored", sha1_to_hex(sha1));
+			error("duplicate parent %s ignored", oid_to_hex(oid));
 			return;
 		}
 		parents_p = &parents->next;

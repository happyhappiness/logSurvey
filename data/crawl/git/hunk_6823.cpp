 	return clean_merge;
 }
 
-int merge_trees(struct tree *head,
+int merge_trees(struct merge_options *o,
+		struct tree *head,
 		struct tree *merge,
 		struct tree *common,
-		const char *branch1,
-		const char *branch2,
 		struct tree **result)
 {
 	int code, clean;
 
-	if (subtree_merge) {
+	if (o->subtree_merge) {
 		merge = shift_tree_object(head, merge);
 		common = shift_tree_object(head, common);
 	}
 
 	if (sha_eq(common->object.sha1, merge->object.sha1)) {
-		output(0, "Already uptodate!");
+		output(o, 0, "Already uptodate!");
 		*result = head;
 		return 1;
 	}

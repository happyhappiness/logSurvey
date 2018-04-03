 	return conflicts ? -1 : 1;
 }
 
-void create_notes_commit(struct notes_tree *t, struct commit_list *parents,
-			 const struct strbuf *msg, unsigned char *result_sha1)
-{
-	unsigned char tree_sha1[20];
-
-	assert(t->initialized);
-
-	if (write_notes_tree(t, tree_sha1))
-		die("Failed to write notes tree to database");
-
-	if (!parents) {
-		/* Deduce parent commit from t->ref */
-		unsigned char parent_sha1[20];
-		if (!read_ref(t->ref, parent_sha1)) {
-			struct commit *parent = lookup_commit(parent_sha1);
-			if (!parent || parse_commit(parent))
-				die("Failed to find/parse commit %s", t->ref);
-			commit_list_insert(parent, &parents);
-		}
-		/* else: t->ref points to nothing, assume root/orphan commit */
-	}
-
-	if (commit_tree(msg, tree_sha1, parents, result_sha1, NULL, NULL))
-		die("Failed to commit notes tree to database");
-}
-
 int notes_merge(struct notes_merge_options *o,
 		struct notes_tree *local_tree,
 		unsigned char *result_sha1)
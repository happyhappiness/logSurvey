 		    typename(expect));
 }
 
-/*
- * Having more than two parents is not strange at all, and this is
- * how multi-way merges are represented.
- */
-#define MAXPARENT (16)
-static unsigned char parent_sha1[MAXPARENT][20];
-
 static const char commit_tree_usage[] = "git-commit-tree <sha1> [-p <sha1>]* < changelog";
 
-static int new_parent(int idx)
+static void new_parent(struct commit *parent, struct commit_list **parents_p)
 {
-	int i;
-	unsigned char *sha1 = parent_sha1[idx];
-	for (i = 0; i < idx; i++) {
-		if (!hashcmp(parent_sha1[i], sha1)) {
+	unsigned char *sha1 = parent->object.sha1;
+	struct commit_list *parents;
+	for (parents = *parents_p; parents; parents = parents->next) {
+		if (parents->item == parent) {
 			error("duplicate parent %s ignored", sha1_to_hex(sha1));
-			return 0;
+			return;
 		}
+		parents_p = &parents->next;
 	}
-	return 1;
+	commit_list_insert(parent, parents_p);
 }
 
 static const char commit_utf8_warn[] =

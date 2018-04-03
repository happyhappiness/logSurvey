  */
 static void do_commit(const struct am_state *state)
 {
-	unsigned char tree[GIT_SHA1_RAWSZ], parent[GIT_SHA1_RAWSZ],
-		      commit[GIT_SHA1_RAWSZ];
-	unsigned char *ptr;
+	struct object_id tree, parent, commit;
+	const struct object_id *old_oid;
 	struct commit_list *parents = NULL;
 	const char *reflog_msg, *author;
 	struct strbuf sb = STRBUF_INIT;
 
 	if (run_hook_le(NULL, "pre-applypatch", NULL))
 		exit(1);
 
-	if (write_cache_as_tree(tree, 0, NULL))
+	if (write_cache_as_tree(tree.hash, 0, NULL))
 		die(_("git write-tree failed to write a tree"));
 
-	if (!get_sha1_commit("HEAD", parent)) {
-		ptr = parent;
-		commit_list_insert(lookup_commit(parent), &parents);
+	if (!get_sha1_commit("HEAD", parent.hash)) {
+		old_oid = &parent;
+		commit_list_insert(lookup_commit(parent.hash), &parents);
 	} else {
-		ptr = NULL;
+		old_oid = NULL;
 		say(state, stderr, _("applying to an empty history"));
 	}
 

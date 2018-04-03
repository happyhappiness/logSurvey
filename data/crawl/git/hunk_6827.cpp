 	return name ? name : branch;
 }
 
-static struct commit *get_ref(const char *ref)
-{
-	unsigned char sha1[20];
-	struct object *object;
-
-	if (get_sha1(ref, sha1))
-		die("Could not resolve ref '%s'", ref);
-	object = deref_tag(parse_object(sha1), ref, strlen(ref));
-	if (!object)
-		return NULL;
-	if (object->type == OBJ_TREE)
-		return make_virtual_commit((struct tree*)object,
-			better_branch_name(ref));
-	if (object->type != OBJ_COMMIT)
-		return NULL;
-	if (parse_commit((struct commit *)object))
-		die("Could not parse commit '%s'", sha1_to_hex(object->sha1));
-	return (struct commit *)object;
-}
-
 int cmd_merge_recursive(int argc, const char **argv, const char *prefix)
 {
-	static const char *bases[20];
-	static unsigned bases_count = 0;
-	int i, clean;
+	const char *bases[21];
+	unsigned bases_count = 0;
+	int i, failed;
 	const char *branch1, *branch2;
-	struct commit *result, *h1, *h2;
-	struct commit_list *ca = NULL;
-	struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
-	int index_fd;
+	unsigned char h1[20], h2[20];
 	int subtree_merge = 0;
 
 	if (argv[0]) {

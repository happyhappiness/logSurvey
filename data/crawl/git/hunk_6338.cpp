 	struct strbuf ref = STRBUF_INIT;
 	int forcing = 0;
 
-	strbuf_branchname(&ref, name);
-	strbuf_splice(&ref, 0, 0, "refs/heads/", 11);
-
-	if (check_ref_format(ref.buf))
+	if (strbuf_check_branch_ref(&ref, name))
 		die("'%s' is not a valid branch name.", name);
 
 	if (resolve_ref(ref.buf, sha1, 1, NULL)) {

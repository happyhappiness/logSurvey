 	return 0;
 }
 
+#define SUMMARY_WIDTH (2 * DEFAULT_ABBREV + 3)
+
 static int update_local_ref(struct ref *ref,
-			    const char *note,
-			    int verbose)
+			    const char *remote,
+			    int verbose,
+			    char *display)
 {
-	char oldh[41], newh[41];
 	struct commit *current = NULL, *updated;
 	enum object_type type;
 	struct branch *current_branch = branch_get(NULL);
+	const char *pretty_ref = ref->name + (
+		!prefixcmp(ref->name, "refs/heads/") ? 11 :
+		!prefixcmp(ref->name, "refs/tags/") ? 10 :
+		!prefixcmp(ref->name, "refs/remotes/") ? 13 :
+		0);
 
+	*display = 0;
 	type = sha1_object_info(ref->new_sha1, NULL);
 	if (type < 0)
 		die("object %s not found", sha1_to_hex(ref->new_sha1));
 
 	if (!*ref->name) {
 		/* Not storing */
-		if (verbose) {
-			fprintf(stderr, "* fetched %s\n", note);
-			show_new(type, ref->new_sha1);
-		}
+		if (verbose)
+			sprintf(display, "* branch %s -> FETCH_HEAD", remote);
 		return 0;
 	}
 
 	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
-		if (verbose) {
-			fprintf(stderr, "* %s: same as %s\n",
-				ref->name, note);
-			show_new(type, ref->new_sha1);
-		}
+		if (verbose)
+			sprintf(display, "= %-*s %s -> %s", SUMMARY_WIDTH,
+				"[up to date]", remote, pretty_ref);
 		return 0;
 	}
 

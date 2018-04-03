 	revs->limited = 1;
 }
 
+static void bisect_common(struct rev_info *revs, const char *prefix,
+			  int *reaches, int *all)
+{
+	bisect_rev_setup(revs, prefix);
+
+	if (prepare_revision_walk(revs))
+		die("revision walk setup failed");
+	if (revs->tree_objects)
+		mark_edges_uninteresting(revs->commits, revs, NULL);
+
+	revs->commits = find_bisection(revs->commits, reaches, all,
+				       !!skipped_sha1_nr);
+}
+
 int bisect_next_vars(const char *prefix)
 {
 	struct rev_info revs;

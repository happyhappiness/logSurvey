 	revs->limited = 1;
 }
 
-static void bisect_common(struct rev_info *revs, const char *prefix,
-			  int *reaches, int *all)
+static void bisect_common(struct rev_info *revs, int *reaches, int *all)
 {
-	bisect_rev_setup(revs, prefix);
-
 	if (prepare_revision_walk(revs))
 		die("revision walk setup failed");
 	if (revs->tree_objects)

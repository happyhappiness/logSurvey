 	if (!revs->dense && !commit->parents->next)
 		return;
 
-	pp = &commit->parents;
-	while ((parent = *pp) != NULL) {
+	for (pp = &commit->parents, nth_parent = 0;
+	     (parent = *pp) != NULL;
+	     pp = &parent->next, nth_parent++) {
 		struct commit *p = parent->item;
 
-		/*
-		 * Do not compare with later parents when we care only about
-		 * the first parent chain, in order to avoid derailing the
-		 * traversal to follow a side branch that brought everything
-		 * in the path we are limited to by the pathspec.
-		 */
-		if (revs->first_parent_only && nth_parent++)
-			break;
+		if (nth_parent == 1) {
+			/*
+			 * This our second loop iteration - so we now know
+			 * we're dealing with a merge.
+			 *
+			 * Do not compare with later parents when we care only about
+			 * the first parent chain, in order to avoid derailing the
+			 * traversal to follow a side branch that brought everything
+			 * in the path we are limited to by the pathspec.
+			 */
+			if (revs->first_parent_only)
+				break;
+			/*
+			 * If this will remain a potentially-simplifiable
+			 * merge, remember per-parent treesame if needed.
+			 * Initialise the array with the comparison from our
+			 * first iteration.
+			 */
+			if (revs->treesame.name &&
+			    !revs->simplify_history &&
+			    !(commit->object.flags & UNINTERESTING)) {
+				ts = initialise_treesame(revs, commit);
+				if (!tree_changed)
+					ts->treesame[0] = 1;
+			}
+		}
 		if (parse_commit(p) < 0)
 			die("cannot simplify commit %s (because of %s)",
 			    sha1_to_hex(commit->object.sha1),
 			    sha1_to_hex(p->object.sha1));
 		switch (rev_compare_tree(revs, p, commit)) {
 		case REV_TREE_SAME:
-			tree_same = 1;
 			if (!revs->simplify_history || (p->object.flags & UNINTERESTING)) {
 				/* Even if a merge with an uninteresting
 				 * side branch brought the entire change
 				 * we are interested in, we do not want
 				 * to lose the other branches of this
 				 * merge, so we just keep going.
 				 */
-				pp = &parent->next;
+				if (ts)
+					ts->treesame[nth_parent] = 1;
 				continue;
 			}
 			parent->next = NULL;

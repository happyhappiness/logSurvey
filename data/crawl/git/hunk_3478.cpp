 
 	if (!*source_tree)                   /* case (1): want a tree */
 		die(_("reference is not a tree: %s"), arg);
-	if (!has_dash_dash) {/* case (3 -> 1) */
+	if (!has_dash_dash) {/* case (3).(d) -> (1) */
 		/*
 		 * Do not complain the most common case
 		 *	git checkout branch

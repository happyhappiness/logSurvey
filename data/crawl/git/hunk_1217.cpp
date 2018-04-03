 	 * changes.
 	 */
 
-	if (run_fallback_merge_recursive(state, orig_tree, our_tree, their_tree)) {
+	init_merge_options(&o);
+
+	o.branch1 = "HEAD";
+	their_tree_name = xstrfmt("%.*s", linelen(state->msg), state->msg);
+	o.branch2 = their_tree_name;
+
+	if (state->quiet)
+		o.verbosity = 0;
+
+	if (merge_recursive_generic(&o, &our_tree, &their_tree, 1, bases, &result)) {
 		rerere(state->allow_rerere_autoupdate);
+		free(their_tree_name);
 		return error(_("Failed to merge in the changes."));
 	}
 
+	free(their_tree_name);
 	return 0;
 }
 

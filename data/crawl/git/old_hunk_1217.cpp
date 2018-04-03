	 * changes.
	 */

	if (run_fallback_merge_recursive(state, orig_tree, our_tree, their_tree)) {
		rerere(state->allow_rerere_autoupdate);
		return error(_("Failed to merge in the changes."));
	}

	return 0;
}


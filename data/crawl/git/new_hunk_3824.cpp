	 * this is not the original behavior and can't be
	 * changed until users trained themselves not to type
	 * "git add -u" or "git add -A". For now, we warn and
	 * keep the old behavior. Later, the behavior can be changed
	 * to tree-wide, keeping the warning for a while, and
	 * eventually we can drop the warning.
	 */
	warning(_("The behavior of 'git add %s (or %s)' with no path argument from a\n"
		  "subdirectory of the tree will change in Git 2.0 and should not be used anymore.\n"
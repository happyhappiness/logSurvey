	 * this is not the original behavior and can't be
	 * changed until users trained themselves not to type
	 * "git add -u" or "git add -A". For now, we warn and
	 * keep the old behavior. Later, this warning can be
	 * turned into a die(...), and eventually we may
	 * reallow the command with a new behavior.
	 */
	warning(_("The behavior of 'git add %s (or %s)' with no path argument from a\n"
		  "subdirectory of the tree will change in Git 2.0 and should not be used anymore.\n"
	 * Set up the revision walk - this will move all commits
	 * from the pending list to the commit walking list.
	 */
	prepare_revision_walk(revs);
	walk_commit_list(revs);
}

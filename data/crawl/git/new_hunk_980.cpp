		 * to work on.
		 */
		if (write_cache_as_tree(head, 0, NULL))
			return error(_("your index file is unmerged."));
	} else {
		unborn = get_sha1("HEAD", head);
		if (unborn)

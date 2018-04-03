		if (write_tree(head, 0, NULL))
			die ("Your index file is unmerged.");
	} else {
		struct wt_status s;

		if (get_sha1("HEAD", head))
			die ("You do not have a valid HEAD");
		wt_status_prepare(&s);
		if (s.commitable)
			die ("Dirty index: cannot %s", me);
		discard_cache();
	}

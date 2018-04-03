
		st = lookup_decoration(&revs->treesame, &commit->object);
		if (!st)
			die("update_treesame %s", sha1_to_hex(commit->object.sha1));
		relevant_parents = 0;
		relevant_change = irrelevant_change = 0;
		for (p = commit->parents, n = 0; p; n++, p = p->next) {

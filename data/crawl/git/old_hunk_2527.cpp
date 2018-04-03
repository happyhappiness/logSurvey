
		if (!opts->mainline)
			return error(_("Commit %s is a merge but no -m option was given."),
				sha1_to_hex(commit->object.sha1));

		for (cnt = 1, p = commit->parents;
		     cnt != opts->mainline && p;
		     cnt++)
			p = p->next;
		if (cnt != opts->mainline || !p)
			return error(_("Commit %s does not have parent %d"),
				sha1_to_hex(commit->object.sha1), opts->mainline);
		parent = p->item;
	} else if (0 < opts->mainline)
		return error(_("Mainline was specified but commit %s is not a merge."),
			sha1_to_hex(commit->object.sha1));
	else
		parent = commit->parents->item;


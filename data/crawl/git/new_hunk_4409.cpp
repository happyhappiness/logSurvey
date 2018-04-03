		struct commit_list *p;

		if (!mainline)
			die(_("Commit %s is a merge but no -m option was given."),
			    sha1_to_hex(commit->object.sha1));

		for (cnt = 1, p = commit->parents;
		     cnt != mainline && p;
		     cnt++)
			p = p->next;
		if (cnt != mainline || !p)
			die(_("Commit %s does not have parent %d"),
			    sha1_to_hex(commit->object.sha1), mainline);
		parent = p->item;
	} else if (0 < mainline)
		die(_("Mainline was specified but commit %s is not a merge."),
		    sha1_to_hex(commit->object.sha1));
	else
		parent = commit->parents->item;

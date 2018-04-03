			item->util = xcalloc(sizeof(struct branch_info), 1);
		info = item->util;
		if (type == REMOTE) {
			if (info->remote)
				warning("more than one branch.%s", key);
			info->remote = xstrdup(value);
		} else {
			char *space = strchr(value, ' ');
			value = abbrev_branch(value);
			while (space) {

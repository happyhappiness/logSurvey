		info = item->util;
		if (type == REMOTE) {
			if (info->remote_name)
				warning("more than one branch.%s", key);
			info->remote_name = xstrdup(value);
		} else {
			char *space = strchr(value, ' ');
			value = abbrev_branch(value);
			while (space) {

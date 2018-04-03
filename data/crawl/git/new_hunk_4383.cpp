		commit = list->item;
		if (has_commit_patch_id(commit, &ids))
			sign = '-';
		print_commit(sign, commit, verbose, abbrev);
		list = list->next;
	}

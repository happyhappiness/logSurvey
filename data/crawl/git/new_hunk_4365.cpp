		commit_list_insert(h2, &(*result)->parents->next);
	}
	flush_output(o);
	if (show(o, 2))
		diff_warn_rename_limit("merge.renamelimit",
				       o->needed_rename_limit, 0);
	return clean;
}


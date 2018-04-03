		commit_list_insert(h2, &(*result)->parents->next);
	}
	flush_output(o);
	if (o->needed_rename_limit)
		warning(rename_limit_advice, o->needed_rename_limit);
	return clean;
}


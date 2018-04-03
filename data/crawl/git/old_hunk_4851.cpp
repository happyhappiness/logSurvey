		commit_list_insert(h2, &(*result)->parents->next);
	}
	flush_output(o);
	return clean;
}


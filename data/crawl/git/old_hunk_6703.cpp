	ce = make_cache_entry(create_ce_mode(active_cache[pos+1]->ce_mode),
			      sha1,
			      path, 2, 0);
	status = checkout_entry(ce, state, NULL);
	return status;
}

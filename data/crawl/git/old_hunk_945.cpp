		struct cache_entry *nce;

		nce = refresh_cache_entry(ce, CE_MATCH_REFRESH | CE_MATCH_IGNORE_MISSING);
		if (nce != ce)
			ret = add_cache_entry(nce, options);
	}

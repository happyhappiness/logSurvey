			struct cache_entry *ce;
			ce = make_cache_entry(one->mode, one->sha1, one->path,
				0, 0);
			add_cache_entry(ce, ADD_CACHE_OK_TO_ADD |
				ADD_CACHE_OK_TO_REPLACE);
		} else
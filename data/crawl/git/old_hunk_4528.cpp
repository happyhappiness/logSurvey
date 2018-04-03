			ce = make_cache_entry(one->mode, one->sha1, one->path,
				0, 0);
			if (!ce)
				die("make_cache_entry failed for path '%s'",
				    one->path);
			add_cache_entry(ce, ADD_CACHE_OK_TO_ADD |
				ADD_CACHE_OK_TO_REPLACE);

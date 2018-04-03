					  path);
			fill_stat_cache_info(ce, &st);
		}
		if (write_sha1_file(buf, size, blob_type, ce->oid.hash) < 0)
			die(_("unable to create backing store for newly created file %s"), path);
	}
	if (add_cache_entry(ce, ADD_CACHE_OK_TO_ADD) < 0)

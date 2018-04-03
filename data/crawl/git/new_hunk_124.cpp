			}
			fill_stat_cache_info(ce, &st);
		}
		if (write_object_file(buf, size, blob_type, &ce->oid) < 0) {
			free(ce);
			return error(_("unable to create backing store "
				       "for newly created file %s"), path);

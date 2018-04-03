		if (0 <= cnt) {
			struct cache_entry *ce = active_cache[cnt];
			if (ce->ce_flags & CE_REMOVE)
				return 0;
		}

		return error("Untracked working tree file '%s' "
			     "would be %s by merge.", ce->name, action);
	}
	return 0;
}

static int merged_entry(struct cache_entry *merge, struct cache_entry *old,

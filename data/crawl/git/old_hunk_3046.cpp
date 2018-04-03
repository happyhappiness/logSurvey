		struct cache_entry *ce = index->cache[i];

		if (ce->ce_flags & CE_UPDATE) {
			display_progress(progress, ++cnt);
			ce->ce_flags &= ~CE_UPDATE;
			if (o->update && !o->dry_run) {

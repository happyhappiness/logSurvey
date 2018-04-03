		return error("Cannot do a oneway merge of %d trees",
			     o->merge_size);

	if (!a)
		return deleted_entry(old, old, o);

	if (old && same(old, a)) {
		int update = 0;
		if (o->reset) {
			struct stat st;
			if (lstat(old->name, &st) ||
			    ie_match_stat(o->src_index, old, &st, CE_MATCH_IGNORE_VALID))
				update |= CE_UPDATE;
		}
		add_entry(o, old, update, 0);
		return 0;
	}
	return merged_entry(a, old, o);
}

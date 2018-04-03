		return error("Cannot do a oneway merge of %d trees",
			     o->merge_size);

	if (!a) {
		remove_entry(remove, o);
		return deleted_entry(old, old, o);
	}
	if (old && same(old, a)) {
		if (o->reset) {
			struct stat st;
			if (lstat(old->name, &st) ||
			    ie_match_stat(o->index, old, &st, CE_MATCH_IGNORE_VALID))
				old->ce_flags |= CE_UPDATE;
		}
		return keep_entry(old, o);
	}
	return merged_entry(a, old, o);
}

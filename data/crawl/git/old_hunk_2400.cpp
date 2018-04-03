		goto done;
	} else if (fast_forward != FF_NO && !remoteheads->next &&
			!common->next &&
			!hashcmp(get_object_hash(common->item->object), get_object_hash(head_commit->object))) {
		/* Again the most common case of merging one remote. */
		struct strbuf msg = STRBUF_INIT;
		struct commit *commit;

		if (verbosity >= 0) {
			char from[GIT_SHA1_HEXSZ + 1], to[GIT_SHA1_HEXSZ + 1];
			find_unique_abbrev_r(from, get_object_hash(head_commit->object),
					      DEFAULT_ABBREV);
			find_unique_abbrev_r(to, get_object_hash(remoteheads->item->object),
					      DEFAULT_ABBREV);
			printf(_("Updating %s..%s\n"), from, to);
		}

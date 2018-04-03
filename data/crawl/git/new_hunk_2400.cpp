		goto done;
	} else if (fast_forward != FF_NO && !remoteheads->next &&
			!common->next &&
			!hashcmp(common->item->object.oid.hash, head_commit->object.oid.hash)) {
		/* Again the most common case of merging one remote. */
		struct strbuf msg = STRBUF_INIT;
		struct commit *commit;

		if (verbosity >= 0) {
			char from[GIT_SHA1_HEXSZ + 1], to[GIT_SHA1_HEXSZ + 1];
			find_unique_abbrev_r(from, head_commit->object.oid.hash,
					      DEFAULT_ABBREV);
			find_unique_abbrev_r(to, remoteheads->item->object.oid.hash,
					      DEFAULT_ABBREV);
			printf(_("Updating %s..%s\n"), from, to);
		}

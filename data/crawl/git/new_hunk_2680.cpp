		/* Again the most common case of merging one remote. */
		struct strbuf msg = STRBUF_INIT;
		struct commit *commit;

		if (verbosity >= 0) {
			char from[GIT_SHA1_HEXSZ + 1], to[GIT_SHA1_HEXSZ + 1];
			find_unique_abbrev_r(from, head_commit->object.sha1,
					      DEFAULT_ABBREV);
			find_unique_abbrev_r(to, remoteheads->item->object.sha1,
					      DEFAULT_ABBREV);
			printf(_("Updating %s..%s\n"), from, to);
		}
		strbuf_addstr(&msg, "Fast-forward");
		if (have_message)
			strbuf_addstr(&msg,

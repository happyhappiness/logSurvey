		struct commit *commit;

		if (verbosity >= 0) {
			printf(_("Updating %s..%s\n"),
			       find_unique_abbrev(head_commit->object.oid.hash,
						  DEFAULT_ABBREV),
			       find_unique_abbrev(remoteheads->item->object.oid.hash,
						  DEFAULT_ABBREV));
		}
		strbuf_addstr(&msg, "Fast-forward");
		if (have_message)

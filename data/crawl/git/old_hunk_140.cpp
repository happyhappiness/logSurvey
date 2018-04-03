		/* Lookup stats on the upstream tracking branch, if set. */
		branch = branch_get(branch_name);
		base = NULL;
		ab_info = (stat_tracking_info(branch, &nr_ahead, &nr_behind,
					      &base, AHEAD_BEHIND_FULL) >= 0);
		if (base) {
			base = shorten_unambiguous_ref(base, 0);
			fprintf(s->fp, "# branch.upstream %s%c", base, eol);
			free((char *)base);

			if (ab_info)
				fprintf(s->fp, "# branch.ab +%d -%d%c", nr_ahead, nr_behind, eol);
		}
	}


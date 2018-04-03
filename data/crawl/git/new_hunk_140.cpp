		/* Lookup stats on the upstream tracking branch, if set. */
		branch = branch_get(branch_name);
		base = NULL;
		ab_info = stat_tracking_info(branch, &nr_ahead, &nr_behind,
					     &base, s->ahead_behind_flags);
		if (base) {
			base = shorten_unambiguous_ref(base, 0);
			fprintf(s->fp, "# branch.upstream %s%c", base, eol);
			free((char *)base);

			if (ab_info > 0) {
				/* different */
				if (nr_ahead || nr_behind)
					fprintf(s->fp, "# branch.ab +%d -%d%c",
						nr_ahead, nr_behind, eol);
				else
					fprintf(s->fp, "# branch.ab +? -?%c",
						eol);
			} else if (!ab_info) {
				/* same */
				fprintf(s->fp, "# branch.ab +0 -0%c", eol);
			}
		}
	}


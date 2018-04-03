
		/* Show sha1's */
		for (i = 0; i < num_parent; i++)
			printf(" %s", diff_unique_abbrev(p->parent[i].oid.hash,
							 opt->abbrev));
		printf(" %s ", diff_unique_abbrev(p->oid.hash, opt->abbrev));
	}

	if (opt->output_format & (DIFF_FORMAT_RAW | DIFF_FORMAT_NAME_STATUS)) {

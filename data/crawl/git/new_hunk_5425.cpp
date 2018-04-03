		else
			fprintf(stdout, "%s\n", summary);
	} else {
		fprintf(stderr, " %c %-*s ", flag, TRANSPORT_SUMMARY_WIDTH, summary);
		if (from)
			fprintf(stderr, "%s -> %s", prettify_refname(from->name), prettify_refname(to->name));
		else

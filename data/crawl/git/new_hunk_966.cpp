		else
			fprintf(stdout, "%s\n", summary);
	} else {
		fprintf(stderr, " %c %-*s ", flag, summary_width, summary);
		if (from)
			fprintf(stderr, "%s -> %s", prettify_refname(from->name), prettify_refname(to->name));
		else

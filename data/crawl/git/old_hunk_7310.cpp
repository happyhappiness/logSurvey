	int inter_name_termination = line_termination ? '\t' : '\0';

	if (!(opt->output_format & DIFF_FORMAT_NAME_STATUS)) {
		printf(":%06o %06o %s ", p->one->mode, p->two->mode,
		       diff_unique_abbrev(p->one->sha1, opt->abbrev));
		printf("%s ", diff_unique_abbrev(p->two->sha1, opt->abbrev));
	}
	if (p->score) {
		printf("%c%03d%c", p->status, similarity_index(p),
			   inter_name_termination);
	} else {
		printf("%c%c", p->status, inter_name_termination);
	}

	if (p->status == DIFF_STATUS_COPIED ||

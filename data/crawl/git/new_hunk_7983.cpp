	return sha1_to_hex(sha1);
}

static void diff_flush_raw(struct diff_filepair *p, struct diff_options *opt)
{
	int line_termination = opt->line_termination;
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

	if (p->status == DIFF_STATUS_COPIED || p->status == DIFF_STATUS_RENAMED) {
		write_name_quoted(p->one->path, stdout, inter_name_termination);
		write_name_quoted(p->two->path, stdout, line_termination);
	} else {
		const char *path = p->one->mode ? p->one->path : p->two->path;
		write_name_quoted(path, stdout, line_termination);
	}
}

int diff_unmodified_pair(struct diff_filepair *p)

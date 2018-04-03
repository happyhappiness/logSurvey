	/*
	 * And then the pretty-printed message itself
	 */
	len = pretty_print_commit(opt->commit_format, commit, ~0u, this_header,
				  sizeof(this_header), abbrev, subject,
				  extra_headers, opt->date_mode);

	if (opt->add_signoff)
		len = append_signoff(this_header, sizeof(this_header), len,
				     opt->add_signoff);
	printf("%s%s%s", this_header, extra, sep);
}

int log_tree_diff_flush(struct rev_info *opt)
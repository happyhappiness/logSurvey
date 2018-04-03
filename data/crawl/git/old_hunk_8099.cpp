	/*
	 * And then the pretty-printed message itself
	 */
	len = pretty_print_commit(opt->commit_format, commit, ~0u,
				  &msgbuf, &msgbuf_len, abbrev, subject,
				  extra_headers, opt->date_mode);

	if (opt->add_signoff)
		len = append_signoff(&msgbuf, &msgbuf_len, len,
				     opt->add_signoff);
	if (opt->show_log_size)
		printf("log size %i\n", len);

	printf("%s%s%s", msgbuf, extra, sep);
	free(msgbuf);
}

int log_tree_diff_flush(struct rev_info *opt)
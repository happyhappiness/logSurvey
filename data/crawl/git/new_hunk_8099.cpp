	/*
	 * And then the pretty-printed message itself
	 */
	strbuf_init(&msgbuf, 0);
	pretty_print_commit(opt->commit_format, commit, &msgbuf,
				  abbrev, subject, extra_headers, opt->date_mode);

	if (opt->add_signoff)
		append_signoff(&msgbuf, opt->add_signoff);
	if (opt->show_log_size)
		printf("log size %i\n", (int)msgbuf.len);

	printf("%s%s%s", msgbuf.buf, extra, sep);
	strbuf_release(&msgbuf);
}

int log_tree_diff_flush(struct rev_info *opt)
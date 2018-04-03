
	ac = parse_options(ac, av, option, mktree_usage, 0);

	while (strbuf_getline(&sb, stdin, line_termination) != EOF)
		mktree_line(sb.buf, sb.len, line_termination);

	strbuf_release(&sb);

	write_tree(sha1);
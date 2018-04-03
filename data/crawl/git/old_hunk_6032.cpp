	unsigned char sha1[20];
	int line_termination = '\n';
	int allow_missing = 0;
	const struct option option[] = {
		OPT_SET_INT('z', NULL, &line_termination, "input is NUL terminated", '\0'),
		OPT_SET_INT( 0 , "missing", &allow_missing, "allow missing objects", 1),
		OPT_END()
	};

	ac = parse_options(ac, av, option, mktree_usage, 0);

	while (strbuf_getline(&sb, stdin, line_termination) != EOF)
		mktree_line(sb.buf, sb.len, line_termination, allow_missing);

	strbuf_release(&sb);

	write_tree(sha1);
	puts(sha1_to_hex(sha1));
	exit(0);
}
	strbuf_setlen(sb, j);
}

int cmd_stripspace(int argc, const char **argv, const char *prefix)
{
	struct strbuf buf = STRBUF_INIT;
	int strip_comments = 0;

	if (argc == 2 && (!strcmp(argv[1], "-s") ||
				!strcmp(argv[1], "--strip-comments")))
		strip_comments = 1;
	else if (argc > 1)
		usage("git stripspace [-s | --strip-comments] < input");

	if (strbuf_read(&buf, 0, 1024) < 0)
		die_errno("could not read the input");

	stripspace(&buf, strip_comments);

	write_or_die(1, buf.buf, buf.len);
	strbuf_release(&buf);

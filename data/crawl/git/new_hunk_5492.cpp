
void read_revisions_from_stdin(struct rev_info *revs)
{
	struct strbuf sb;

	strbuf_init(&sb, 1000);
	while (strbuf_getwholeline(&sb, stdin, '\n') != EOF) {
		int len = sb.len;
		if (len && sb.buf[len - 1] == '\n')
			sb.buf[--len] = '\0';
		if (!len)
			break;
		if (sb.buf[0] == '-')
			die("options not supported in --stdin mode");
		if (handle_revision_arg(sb.buf, revs, 0, 1))
			die("bad revision '%s'", sb.buf);
	}
	strbuf_release(&sb);
}

static void add_grep(struct rev_info *revs, const char *ptn, enum grep_pat_token what)
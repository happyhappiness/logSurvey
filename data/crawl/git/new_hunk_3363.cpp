	strbuf_release(&pattern);
}

void wt_status_add_cut_line(FILE *fp)
{
	const char *explanation = _("Do not touch the line above.\nEverything below will be removed.");
	struct strbuf buf = STRBUF_INIT;

	fprintf(fp, "%c %s", comment_line_char, cut_line);
	strbuf_add_commented_lines(&buf, explanation, strlen(explanation));
	fputs(buf.buf, fp);
	strbuf_release(&buf);
}

static void wt_status_print_verbose(struct wt_status *s)
{
	struct rev_info rev;

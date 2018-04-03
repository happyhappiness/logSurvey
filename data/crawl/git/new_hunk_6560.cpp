
static void show_tagger(char *buf, int len, struct rev_info *rev)
{
	struct strbuf out = STRBUF_INIT;

	pp_user_info("Tagger", rev->commit_format, &out, buf, rev->date_mode,
		git_log_output_encoding ?
		git_log_output_encoding: git_commit_encoding);
	printf("%s\n", out.buf);
	strbuf_release(&out);
}

static int show_object(const unsigned char *sha1, int show_tag_object,
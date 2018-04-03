				struct wt_status_state *state,
				const char *color)
{
	if (state->branch)
		status_printf_ln(s, color,
				 _("You are currently bisecting branch '%s'."),
				 state->branch);
	else
		status_printf_ln(s, color,
				 _("You are currently bisecting."));
	if (advice_status_hints)
		status_printf_ln(s, color,
			_("  (use \"git bisect reset\" to get back to the original branch)"));
	wt_status_print_trailer(s);
}

/*
 * Extract branch information from rebase/bisect
 */
static void read_and_strip_branch(struct strbuf *sb,
				  const char **branch,
				  const char *path)
{
	unsigned char sha1[20];

	strbuf_reset(sb);
	if (strbuf_read_file(sb, git_path("%s", path), 0) <= 0)
		return;

	while (sb->len && sb->buf[sb->len - 1] == '\n')
		strbuf_setlen(sb, sb->len - 1);
	if (!sb->len)
		return;
	if (!prefixcmp(sb->buf, "refs/heads/"))
		*branch = sb->buf + strlen("refs/heads/");
	else if (!prefixcmp(sb->buf, "refs/"))
		*branch = sb->buf;
	else if (!get_sha1_hex(sb->buf, sha1)) {
		const char *abbrev;
		abbrev = find_unique_abbrev(sha1, DEFAULT_ABBREV);
		strbuf_reset(sb);
		strbuf_addstr(sb, abbrev);
		*branch = sb->buf;
	} else if (!strcmp(sb->buf, "detached HEAD")) /* rebase */
		;
	else			/* bisect */
		*branch = sb->buf;
}

static void wt_status_print_state(struct wt_status *s)
{
	const char *state_color = color(WT_STATUS_HEADER, s);
	struct strbuf branch = STRBUF_INIT;
	struct strbuf onto = STRBUF_INIT;
	struct wt_status_state state;
	struct stat st;


	return 0;
}

/**
 * Commits the current index with state->msg as the commit message and
 * state->author_name, state->author_email and state->author_date as the author
 * information.
 */
static void do_commit(const struct am_state *state)
{
	unsigned char tree[GIT_SHA1_RAWSZ], parent[GIT_SHA1_RAWSZ],
		      commit[GIT_SHA1_RAWSZ];
	unsigned char *ptr;
	struct commit_list *parents = NULL;
	const char *reflog_msg, *author;
	struct strbuf sb = STRBUF_INIT;

	if (write_cache_as_tree(tree, 0, NULL))
		die(_("git write-tree failed to write a tree"));

	if (!get_sha1_commit("HEAD", parent)) {
		ptr = parent;
		commit_list_insert(lookup_commit(parent), &parents);
	} else {
		ptr = NULL;
		fprintf_ln(stderr, _("applying to an empty history"));
	}

	author = fmt_ident(state->author_name, state->author_email,
			state->author_date, IDENT_STRICT);

	if (commit_tree(state->msg, state->msg_len, tree, parents, commit,
				author, NULL))
		die(_("failed to write commit object"));

	reflog_msg = getenv("GIT_REFLOG_ACTION");
	if (!reflog_msg)
		reflog_msg = "am";

	strbuf_addf(&sb, "%s: %.*s", reflog_msg, linelen(state->msg),
			state->msg);

	update_ref(sb.buf, "HEAD", commit, ptr, 0, UPDATE_REFS_DIE_ON_ERR);

	strbuf_release(&sb);
}

/**
 * Applies all queued mail.
 */
static void am_run(struct am_state *state)
{
	const char *argv_gc_auto[] = {"gc", "--auto", NULL};

	refresh_and_write_cache();

	while (state->cur <= state->last) {

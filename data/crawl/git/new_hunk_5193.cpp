static const char *tag_skip_worktree = "";
static const char *tag_resolve_undo = "";

static void write_name(const char* name, size_t len)
{
	write_name_quoted_relative(name, len, prefix, prefix_len, stdout,
			line_terminator);
}

static void show_dir_entry(const char *tag, struct dir_entry *ent)
{
	int len = max_prefix_len;

	if (len >= ent->len)
		die("git ls-files: internal error - directory entry not superset of prefix");

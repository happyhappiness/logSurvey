static const char *tag_skip_worktree = "";
static const char *tag_resolve_undo = "";

static void show_dir_entry(const char *tag, struct dir_entry *ent)
{
	int len = prefix_len;
	int offset = prefix_offset;

	if (len >= ent->len)
		die("git ls-files: internal error - directory entry not superset of prefix");

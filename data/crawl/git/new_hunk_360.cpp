	}
}

static void show_files(struct repository *repo, struct dir_struct *dir);

static void show_submodule(struct repository *superproject,
			   struct dir_struct *dir, const char *path)
{
	struct repository submodule;

	if (repo_submodule_init(&submodule, superproject, path))
		return;

	if (repo_read_index(&submodule) < 0)
		die("index file corrupt");

	repo_read_gitmodules(&submodule);

	show_files(&submodule, dir);

	repo_clear(&submodule);
}

static void show_ce(struct repository *repo, struct dir_struct *dir,
		    const struct cache_entry *ce, const char *fullname,
		    const char *tag)
{
	if (max_prefix_len > strlen(fullname))
		die("git ls-files: internal error - cache entry not superset of prefix");

	if (recurse_submodules && S_ISGITLINK(ce->ce_mode) &&
	    is_submodule_active(repo, ce->name)) {
		show_submodule(repo, dir, ce->name);
	} else if (match_pathspec(&pathspec, fullname, strlen(fullname),
				  max_prefix_len, ps_matched,
				  S_ISDIR(ce->ce_mode) ||
				  S_ISGITLINK(ce->ce_mode))) {
		tag = get_tag(ce, tag);

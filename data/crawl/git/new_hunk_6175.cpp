	return errors;
}

static const char * const ls_files_usage[] = {
	"git ls-files [options] [<file>]*",
	NULL
};

static int option_parse_z(const struct option *opt,
			  const char *arg, int unset)
{
	line_terminator = unset ? '\n' : '\0';

	return 0;
}

static int option_parse_exclude(const struct option *opt,
				const char *arg, int unset)
{
	struct exclude_list *list = opt->value;

	exc_given = 1;
	add_exclude(arg, "", 0, list);

	return 0;
}

static int option_parse_exclude_from(const struct option *opt,
				     const char *arg, int unset)
{
	struct dir_struct *dir = opt->value;

	exc_given = 1;
	add_excludes_from_file(dir, arg);

	return 0;
}

static int option_parse_exclude_standard(const struct option *opt,
					 const char *arg, int unset)
{
	struct dir_struct *dir = opt->value;

	exc_given = 1;
	setup_standard_excludes(dir);

	return 0;
}

int cmd_ls_files(int argc, const char **argv, const char *prefix)
{
	int require_work_tree = 0, show_tag = 0;
	struct dir_struct dir;
	struct option builtin_ls_files_options[] = {
		{ OPTION_CALLBACK, 'z', NULL, NULL, NULL,
			"paths are separated with NUL character",
			PARSE_OPT_NOARG, option_parse_z },
		OPT_BOOLEAN('t', NULL, &show_tag,
			"identify the file status with tags"),
		OPT_BOOLEAN('v', NULL, &show_valid_bit,
			"use lowercase letters for 'assume unchanged' files"),
		OPT_BOOLEAN('c', "cached", &show_cached,
			"show cached files in the output (default)"),
		OPT_BOOLEAN('d', "deleted", &show_deleted,
			"show deleted files in the output"),
		OPT_BOOLEAN('m', "modified", &show_modified,
			"show modified files in the output"),
		OPT_BOOLEAN('o', "others", &show_others,
			"show other files in the output"),
		OPT_BIT('i', "ignored", &dir.flags,
			"show ignored files in the output",
			DIR_SHOW_IGNORED),
		OPT_BOOLEAN('s', "stage", &show_stage,
			"show staged contents' object name in the output"),
		OPT_BOOLEAN('k', "killed", &show_killed,
			"show files on the filesystem that need to be removed"),
		OPT_BIT(0, "directory", &dir.flags,
			"show 'other' directories' name only",
			DIR_SHOW_OTHER_DIRECTORIES),
		OPT_BIT(0, "no-empty-directory", &dir.flags,
			"don't show empty directories",
			DIR_HIDE_EMPTY_DIRECTORIES),
		OPT_BOOLEAN('u', "unmerged", &show_unmerged,
			"show unmerged files in the output"),
		{ OPTION_CALLBACK, 'x', "exclude", &dir.exclude_list[EXC_CMDL], "pattern",
			"skip files matching pattern",
			0, option_parse_exclude },
		{ OPTION_CALLBACK, 'X', "exclude-from", &dir, "file",
			"exclude patterns are read from <file>",
			0, option_parse_exclude_from },
		OPT_STRING(0, "exclude-per-directory", &dir.exclude_per_dir, "file",
			"read additional per-directory exclude patterns in <file>"),
		{ OPTION_CALLBACK, 0, "exclude-standard", &dir, NULL,
			"add the standard git exclusions",
			PARSE_OPT_NOARG, option_parse_exclude_standard },
		{ OPTION_SET_INT, 0, "full-name", &prefix_offset, NULL,
			"make the output relative to the project top directory",
			PARSE_OPT_NOARG | PARSE_OPT_NONEG, NULL },
		OPT_BOOLEAN(0, "error-unmatch", &error_unmatch,
			"if any <file> is not in the index, treat this as an error"),
		OPT_STRING(0, "with-tree", &with_tree, "tree-ish",
			"pretend that paths removed since <tree-ish> are still present"),
		OPT__ABBREV(&abbrev),
		OPT_END()
	};

	memset(&dir, 0, sizeof(dir));
	if (prefix)
		prefix_offset = strlen(prefix);
	git_config(git_default_config, NULL);

	argc = parse_options(argc, argv, builtin_ls_files_options,
			ls_files_usage, 0);
	if (show_tag || show_valid_bit) {
		tag_cached = "H ";
		tag_unmerged = "M ";
		tag_removed = "R ";
		tag_modified = "C ";
		tag_other = "? ";
		tag_killed = "K ";
	}
	if (show_modified || show_others || show_deleted || (dir.flags & DIR_SHOW_IGNORED) || show_killed)
		require_work_tree = 1;
	if (show_unmerged)
		/*
		 * There's no point in showing unmerged unless
		 * you also show the stage information.
		 */
		show_stage = 1;
	if (dir.exclude_per_dir)
		exc_given = 1;

	if (require_work_tree && !is_inside_work_tree())
		setup_work_tree();

	pathspec = get_pathspec(prefix, argv);

	/* be nice with submodule patsh ending in a slash */
	read_cache();

#define DIFF_OLD_NAME 0
#define DIFF_NEW_NAME 1

static char *gitdiff_verify_name(const char *line, int isnull, char *orig_name, int side)
{
	if (!orig_name && !isnull)
		return find_name(line, NULL, p_value, TERM_TAB);

	if (orig_name) {
		int len = strlen(orig_name);
		char *another;
		if (isnull)
			die(_("git apply: bad git-diff - expected /dev/null, got %s on line %d"),
			    orig_name, linenr);
		another = find_name(line, NULL, p_value, TERM_TAB);
		if (!another || memcmp(another, orig_name, len + 1))
			die((side == DIFF_NEW_NAME) ?
			    _("git apply: bad git-diff - inconsistent new filename on line %d") :
			    _("git apply: bad git-diff - inconsistent old filename on line %d"), linenr);
		free(another);
		return orig_name;
	} else {
		/* expect "/dev/null" */
		if (memcmp("/dev/null", line, 9) || line[9] != '\n')
			die(_("git apply: bad git-diff - expected /dev/null on line %d"), linenr);
		return NULL;
	}
}

static int gitdiff_oldname(const char *line, struct patch *patch)
{
	patch->old_name = gitdiff_verify_name(line, patch->is_new, patch->old_name,
					      DIFF_OLD_NAME);
	return 0;
}

static int gitdiff_newname(const char *line, struct patch *patch)
{
	patch->new_name = gitdiff_verify_name(line, patch->is_delete, patch->new_name,
					      DIFF_NEW_NAME);
	return 0;
}

static int gitdiff_oldmode(const char *line, struct patch *patch)
{
	patch->old_mode = strtoul(line, NULL, 8);
	return 0;
}

static int gitdiff_newmode(const char *line, struct patch *patch)
{
	patch->new_mode = strtoul(line, NULL, 8);
	return 0;
}

static int gitdiff_delete(const char *line, struct patch *patch)
{
	patch->is_delete = 1;
	free(patch->old_name);
	patch->old_name = xstrdup_or_null(patch->def_name);
	return gitdiff_oldmode(line, patch);
}

static int gitdiff_newfile(const char *line, struct patch *patch)
{
	patch->is_new = 1;
	free(patch->new_name);
	patch->new_name = xstrdup_or_null(patch->def_name);
	return gitdiff_newmode(line, patch);
}

static int gitdiff_copysrc(const char *line, struct patch *patch)
{
	patch->is_copy = 1;
	free(patch->old_name);
	patch->old_name = find_name(line, NULL, p_value ? p_value - 1 : 0, 0);
	return 0;
}

static int gitdiff_copydst(const char *line, struct patch *patch)
{
	patch->is_copy = 1;
	free(patch->new_name);
	patch->new_name = find_name(line, NULL, p_value ? p_value - 1 : 0, 0);
	return 0;
}

static int gitdiff_renamesrc(const char *line, struct patch *patch)
{
	patch->is_rename = 1;
	free(patch->old_name);
	patch->old_name = find_name(line, NULL, p_value ? p_value - 1 : 0, 0);
	return 0;
}

static int gitdiff_renamedst(const char *line, struct patch *patch)
{
	patch->is_rename = 1;
	free(patch->new_name);
	patch->new_name = find_name(line, NULL, p_value ? p_value - 1 : 0, 0);
	return 0;
}

static int gitdiff_similarity(const char *line, struct patch *patch)
{
	unsigned long val = strtoul(line, NULL, 10);
	if (val <= 100)
		patch->score = val;
	return 0;
}

static int gitdiff_dissimilarity(const char *line, struct patch *patch)
{
	unsigned long val = strtoul(line, NULL, 10);
	if (val <= 100)
		patch->score = val;
	return 0;
}

static int gitdiff_index(const char *line, struct patch *patch)
{
	/*
	 * index line is N hexadecimal, "..", N hexadecimal,
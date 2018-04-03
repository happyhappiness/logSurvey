
void add_excludes_from_file(struct dir_struct *dir, const char *fname)
{
	if (add_excludes_from_file_1(fname, "", 0,
				     &dir->exclude_list[EXC_FILE]) < 0)
		die("cannot use %s as an exclude file", fname);
}

int push_exclude_per_directory(struct dir_struct *dir, const char *base, int baselen)
{
	char exclude_file[PATH_MAX];
	struct exclude_list *el = &dir->exclude_list[EXC_DIRS];
	int current_nr = el->nr;

	if (dir->exclude_per_dir) {
		memcpy(exclude_file, base, baselen);
		strcpy(exclude_file + baselen, dir->exclude_per_dir);
		add_excludes_from_file_1(exclude_file, base, baselen, el);
	}
	return current_nr;
}

void pop_exclude_per_directory(struct dir_struct *dir, int stk)
{
	struct exclude_list *el = &dir->exclude_list[EXC_DIRS];

	while (stk < el->nr)
		free(el->excludes[--el->nr]);
}

/* Scan the list and let the last match determines the fate.

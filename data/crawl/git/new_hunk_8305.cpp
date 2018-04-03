static int merge_entry(int pos, const char *path)
{
	int found;

	if (pos >= active_nr)
		die("git-merge-index: %s not in the cache", path);
	arguments[0] = pgm;

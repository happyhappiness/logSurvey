        free(seen);
}

static void fill_directory(struct dir_struct *dir, const char **pathspec,
		int ignored_too)
{

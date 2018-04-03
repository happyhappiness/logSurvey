	}
	dir->nr = dst - dir->entries;
	fill_pathspec_matches(pathspec, seen, specs);
	return seen;
}

static void treat_gitlinks(const char **pathspec)

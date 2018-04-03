	}
	dir->nr = dst - dir->entries;
	fill_pathspec_matches(pathspec, seen, specs);

	for (i = 0; i < specs; i++) {
		if (!seen[i] && pathspec[i][0] && !file_exists(pathspec[i]))
			die("pathspec '%s' did not match any files",
					pathspec[i]);
	}
        free(seen);
}

static void treat_gitlinks(const char **pathspec)

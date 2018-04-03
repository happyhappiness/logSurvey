	}

	if (!initialized) {
		initialized = 1;
		prereleases = git_config_get_value_multi("versionsort.prereleasesuffix");
	}
	if (prereleases && swap_prereleases(s1, s2, (const char *) p1 - s1 - 1,
					    &diff))
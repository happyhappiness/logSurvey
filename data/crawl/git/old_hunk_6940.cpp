			dirname);
		return;
	}
	while ((de = readdir(dir)) != NULL) {
		if (!prefixcmp(de->d_name, "tmp_")) {
			char name[PATH_MAX];
			int c = snprintf(name, PATH_MAX, "%s/%s",
					 dirname, de->d_name);
			if (c < 0 || c >= PATH_MAX)
				continue;
			if (expire) {
				struct stat st;
				if (stat(name, &st) != 0 || st.st_mtime >= expire)
					continue;
			}
			printf("Removing stale temporary file %s\n", name);
			if (!show_only)
				unlink(name);
		}
	}
	closedir(dir);
}

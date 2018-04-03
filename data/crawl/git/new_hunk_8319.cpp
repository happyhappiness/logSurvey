			filename[len++] = '/';
	}

	if (numbered_files) {
		sprintf(filename + len, "%d", nr);
		len = strlen(filename);

	} else {
		sprintf(filename + len, "%04d", nr);
		len = strlen(filename);

		sol = strstr(commit->buffer, "\n\n");
		if (sol) {
			int j, space = 1;

			sol += 2;
			/* strip [PATCH] or [PATCH blabla] */
			if (!keep_subject && !prefixcmp(sol, "[PATCH")) {
				char *eos = strchr(sol + 6, ']');
				if (eos) {
					while (isspace(*eos))
						eos++;
					sol = eos;
				}
			}

			for (j = 0;
			     j < FORMAT_PATCH_NAME_MAX - suffix_len - 5 &&
				     len < sizeof(filename) - suffix_len &&
				     sol[j] && sol[j] != '\n';
			     j++) {
				if (istitlechar(sol[j])) {
					if (space) {
						filename[len++] = '-';
						space = 0;
					}
					filename[len++] = sol[j];
					if (sol[j] == '.')
						while (sol[j + 1] == '.')
							j++;
				} else
					space = 1;
			}
			while (filename[len - 1] == '.'
			       || filename[len - 1] == '-')
				len--;
			filename[len] = 0;
		}
		if (len + suffix_len >= sizeof(filename))
			return error("Patch pathname too long");
		strcpy(filename + len, fmt_patch_suffix);
	}

	fprintf(realstdout, "%s\n", filename);
	if (freopen(filename, "w", stdout) == NULL)
		return error("Cannot open patch file %s",filename);

	return 0;
}

static void get_patch_ids(struct rev_info *rev, struct patch_ids *ids, const char *prefix)

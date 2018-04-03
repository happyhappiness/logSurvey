		exit(1);
}

static char *get_oneline(const char *message)
{
	char *result;
	const char *p = message, *abbrev, *eol;
	int abbrev_len, oneline_len;

	if (!p)
		die ("Could not read commit message of %s",
				sha1_to_hex(commit->object.sha1));
	while (*p && (*p != '\n' || p[1] != '\n'))
		p++;

	if (*p) {
		p += 2;
		for (eol = p + 1; *eol && *eol != '\n'; eol++)
			; /* do nothing */
	} else
		eol = p;
	abbrev = find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV);
	abbrev_len = strlen(abbrev);
	oneline_len = eol - p;
	result = xmalloc(abbrev_len + 5 + oneline_len);
	memcpy(result, abbrev, abbrev_len);
	memcpy(result + abbrev_len, "... ", 4);
	memcpy(result + abbrev_len + 4, p, oneline_len);
	result[abbrev_len + 4 + oneline_len] = '\0';
	return result;
}

static char *get_encoding(const char *message)

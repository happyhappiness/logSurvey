
static void read_from_stdin(struct path_list *list)
{
	char author[1024], oneline[1024];

	while (fgets(author, sizeof(author), stdin) != NULL) {
		if (!(author[0] == 'A' || author[0] == 'a') ||
		    prefixcmp(author + 1, "uthor: "))
			continue;
		while (fgets(oneline, sizeof(oneline), stdin) &&
		       oneline[0] != '\n')
			; /* discard headers */
		while (fgets(oneline, sizeof(oneline), stdin) &&
		       oneline[0] == '\n')
			; /* discard blanks */
		insert_one_record(list, author + 8, oneline);
	}
}

static void get_from_rev(struct rev_info *rev, struct path_list *list)
{
	struct commit *commit;

	prepare_revision_walk(rev);
	while ((commit = get_revision(rev)) != NULL) {
		const char *author = NULL, *buffer;

		buffer = commit->buffer;
		while (*buffer && *buffer != '\n') {
			const char *eol = strchr(buffer, '\n');

			if (eol == NULL)
				eol = buffer + strlen(buffer);
			else
				eol++;

			if (!prefixcmp(buffer, "author "))
				author = buffer + 7;
			buffer = eol;
		}
		if (!author)
			die("Missing author: %s",
			    sha1_to_hex(commit->object.sha1));
		if (*buffer)
			buffer++;
		insert_one_record(list, author, !*buffer ? "<none>" : buffer);
	}
}

static int parse_uint(char const **arg, int comma)
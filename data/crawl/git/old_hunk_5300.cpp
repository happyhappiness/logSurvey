	commit_list_insert(parent, parents_p);
}

static const char commit_utf8_warn[] =
"Warning: commit message does not conform to UTF-8.\n"
"You may want to amend it after fixing the message, or set the config\n"
"variable i18n.commitencoding to the encoding your project uses.\n";

int commit_tree(const char *msg, unsigned char *tree,
		struct commit_list *parents, unsigned char *ret,
		const char *author)
{
	int result;
	int encoding_is_utf8;
	struct strbuf buffer;

	check_valid(tree, OBJ_TREE);

	/* Not having i18n.commitencoding is the same as having utf-8 */
	encoding_is_utf8 = is_encoding_utf8(git_commit_encoding);

	strbuf_init(&buffer, 8192); /* should avoid reallocs for the headers */
	strbuf_addf(&buffer, "tree %s\n", sha1_to_hex(tree));

	/*
	 * NOTE! This ordering means that the same exact tree merged with a
	 * different order of parents will be a _different_ changeset even
	 * if everything else stays the same.
	 */
	while (parents) {
		struct commit_list *next = parents->next;
		strbuf_addf(&buffer, "parent %s\n",
			sha1_to_hex(parents->item->object.sha1));
		free(parents);
		parents = next;
	}

	/* Person/date information */
	if (!author)
		author = git_author_info(IDENT_ERROR_ON_NO_NAME);
	strbuf_addf(&buffer, "author %s\n", author);
	strbuf_addf(&buffer, "committer %s\n", git_committer_info(IDENT_ERROR_ON_NO_NAME));
	if (!encoding_is_utf8)
		strbuf_addf(&buffer, "encoding %s\n", git_commit_encoding);
	strbuf_addch(&buffer, '\n');

	/* And add the comment */
	strbuf_addstr(&buffer, msg);

	/* And check the encoding */
	if (encoding_is_utf8 && !is_utf8(buffer.buf))
		fprintf(stderr, commit_utf8_warn);

	result = write_sha1_file(buffer.buf, buffer.len, commit_type, ret);
	strbuf_release(&buffer);
	return result;
}

int cmd_commit_tree(int argc, const char **argv, const char *prefix)
{
	int i;

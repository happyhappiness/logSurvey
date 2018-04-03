"You may want to amend it after fixing the message, or set the config\n"
"variable i18n.commitencoding to the encoding your project uses.\n";

int commit_tree(const char *msg, unsigned char *tree,
		struct commit_list *parents, unsigned char *ret)
{
	int encoding_is_utf8;
	struct strbuf buffer;

	check_valid(tree, OBJ_TREE);

	/* Not having i18n.commitencoding is the same as having utf-8 */
	encoding_is_utf8 = is_encoding_utf8(git_commit_encoding);

	strbuf_init(&buffer, 8192); /* should avoid reallocs for the headers */
	strbuf_addf(&buffer, "tree %s\n", sha1_to_hex(tree));

	/*
	 * NOTE! This ordering means that the same exact tree merged with a

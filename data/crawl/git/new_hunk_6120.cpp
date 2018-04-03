	char *real_ref, msg[PATH_MAX + 20];
	struct strbuf ref = STRBUF_INIT;
	int forcing = 0;

	if (strbuf_check_branch_ref(&ref, name))
		die("'%s' is not a valid branch name.", name);

	if (resolve_ref(ref.buf, sha1, 1, NULL)) {

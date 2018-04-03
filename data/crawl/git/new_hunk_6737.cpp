"You may want to amend it after fixing the message, or set the config\n"
"variable i18n.commitencoding to the encoding your project uses.\n";

int cmd_commit(int argc, const char **argv, const char *prefix)
{
	struct strbuf sb;
	const char *index_file, *reflog_msg;
	char *nl, *p;
	unsigned char commit_sha1[20];
	struct ref_lock *ref_lock;
	struct commit_list *parents = NULL, **pptr = &parents;

	git_config(git_commit_config, NULL);


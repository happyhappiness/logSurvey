			      const char *refname)
{
	if (!refname) {
		strbuf_git_path(sb, "logs");
		return;
	}

	strbuf_git_path(sb, "logs/%s", refname);
}

static void files_ref_path(struct files_ref_store *refs,

	strbuf_release(&sb);
}

void show_submodule_summary(FILE *f, const char *path,
		const char *line_prefix,
		struct object_id *one, struct object_id *two,
		unsigned dirty_submodule, const char *meta,
		const char *del, const char *add, const char *reset)
{
	struct rev_info rev;
	struct commit *left = NULL, *right = NULL;
	const char *message = NULL;
	struct strbuf sb = STRBUF_INIT;
	int fast_forward = 0, fast_backward = 0;

	if (is_null_oid(two))
		message = "(submodule deleted)";
	else if (add_submodule_odb(path))
		message = "(not initialized)";
	else if (is_null_oid(one))
		message = "(new submodule)";
	else if (!(left = lookup_commit_reference(one->hash)) ||
		 !(right = lookup_commit_reference(two->hash)))
		message = "(commits not present)";
	else if (prepare_submodule_summary(&rev, path, left, right,
					   &fast_forward, &fast_backward))
		message = "(revision walker failed)";

	if (dirty_submodule & DIRTY_SUBMODULE_UNTRACKED)
		fprintf(f, "%sSubmodule %s contains untracked content\n",
			line_prefix, path);
	if (dirty_submodule & DIRTY_SUBMODULE_MODIFIED)
		fprintf(f, "%sSubmodule %s contains modified content\n",
			line_prefix, path);

	if (!oidcmp(one, two)) {
		strbuf_release(&sb);
		return;
	}

	strbuf_addf(&sb, "%s%sSubmodule %s %s..", line_prefix, meta, path,
			find_unique_abbrev(one->hash, DEFAULT_ABBREV));
	if (!fast_backward && !fast_forward)

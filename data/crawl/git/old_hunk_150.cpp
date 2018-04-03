	strbuf_release(&format);
}

static int is_original_commit_empty(struct commit *commit)
{
	const struct object_id *ptree_oid;

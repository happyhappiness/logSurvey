	run_rewrite_hook(&old_head->object.oid, new_head);
}

static int is_original_commit_empty(struct commit *commit)
{
	const struct object_id *ptree_oid;

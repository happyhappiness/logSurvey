	add_pending_object(&revs, object, oid_to_hex(&object->oid));

	for_each_ref(add_pending_uninteresting_ref, &revs);
	add_pending_oid(&revs, "HEAD", &new_commit->object.oid, UNINTERESTING);

	if (prepare_revision_walk(&revs))
		die(_("internal error in revision walk"));
	if (!(old_commit->object.flags & UNINTERESTING))
		suggest_reattach(old_commit, &revs);
	else
		describe_detached_head(_("Previous HEAD position was"), old_commit);

	/* Clean up objects used, as they will be reused. */
	clear_commit_marks_all(ALL_REV_FLAGS);
}

static int switch_branches(const struct checkout_opts *opts,
			   struct branch_info *new_branch_info)
{
	int ret = 0;
	struct branch_info old_branch_info;
	void *path_to_free;
	struct object_id rev;
	int flag, writeout_error = 0;
	memset(&old_branch_info, 0, sizeof(old_branch_info));
	old_branch_info.path = path_to_free = resolve_refdup("HEAD", 0, &rev, &flag);
	if (old_branch_info.path)
		old_branch_info.commit = lookup_commit_reference_gently(&rev, 1);
	if (!(flag & REF_ISSYMREF))
		old_branch_info.path = NULL;

	if (old_branch_info.path)
		skip_prefix(old_branch_info.path, "refs/heads/", &old_branch_info.name);

	if (!new_branch_info->name) {
		new_branch_info->name = "HEAD";
		new_branch_info->commit = old_branch_info.commit;
		if (!new_branch_info->commit)
			die(_("You are on a branch yet to be born"));
		parse_commit_or_die(new_branch_info->commit);
	}

	ret = merge_working_tree(opts, &old_branch_info, new_branch_info, &writeout_error);
	if (ret) {
		free(path_to_free);
		return ret;
	}

	if (!opts->quiet && !old_branch_info.path && old_branch_info.commit && new_branch_info->commit != old_branch_info.commit)
		orphaned_commit_warning(old_branch_info.commit, new_branch_info->commit);

	update_refs_for_switch(opts, &old_branch_info, new_branch_info);

	ret = post_checkout_hook(old_branch_info.commit, new_branch_info->commit, 1);
	free(path_to_free);
	return ret || writeout_error;
}

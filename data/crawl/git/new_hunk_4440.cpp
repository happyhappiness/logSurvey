	unsigned int unannotated_cnt = 0;

	if (get_sha1(arg, sha1))
		die(_("Not a valid object name %s"), arg);
	cmit = lookup_commit_reference(sha1);
	if (!cmit)
		die(_("%s is not a valid '%s' object"), arg, commit_type);

	n = find_commit_name(cmit->object.sha1);
	if (n && (tags || all || n->prio == 2)) {

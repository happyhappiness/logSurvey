
	if ((commit = lookup_commit_reference(sha1)) == NULL)
		die(_("Not a valid branch point: '%s'."), start_name);
	hashcpy(sha1, commit->object.sha1);

	if (forcing)
		snprintf(msg, sizeof msg, "branch: Reset to %s",

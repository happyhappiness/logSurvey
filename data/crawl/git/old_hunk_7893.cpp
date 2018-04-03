
	if (!commit->parents)
		die ("Cannot %s a root commit", me);
	if (commit->parents->next)
		die ("Cannot %s a multi-parent commit.", me);
	if (!(message = commit->buffer))
		die ("Cannot get commit message for %s",
				sha1_to_hex(commit->object.sha1));

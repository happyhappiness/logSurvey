{
	struct remote *remote;

	if (!branch)
		return error_buf(err, _("HEAD does not point to a branch"));

	remote = remote_get(pushremote_for_branch(branch, NULL));
	if (!remote)
		return error_buf(err,

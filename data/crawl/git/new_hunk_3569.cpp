	warning("%s\n", _(warn_unspecified_push_default_msg));
}

static int is_workflow_triangular(struct remote *remote)
{
	struct remote *fetch_remote = remote_get(NULL);
	return (fetch_remote && fetch_remote != remote);
}

static void setup_default_push_refspecs(struct remote *remote)
{
	struct branch *branch = branch_get(NULL);
	int triangular = is_workflow_triangular(remote);

	switch (push_default) {
	default:

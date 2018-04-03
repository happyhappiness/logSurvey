	warning("%s\n", _(warn_unspecified_push_default_msg));
}

static void setup_default_push_refspecs(struct remote *remote)
{
	struct branch *branch;

	switch (push_default) {
	default:

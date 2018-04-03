}

static struct ref *do_fetch_pack(int fd[2],
		const struct ref *orig_ref,
		int nr_match,
		char **match,
		char **pack_lockfile)
{
	struct ref *ref = copy_ref_list(orig_ref);
	unsigned char sha1[20];

	if (is_repository_shallow() && !server_supports("shallow"))
		die("Server does not support shallow clients");
	if (server_supports("multi_ack")) {

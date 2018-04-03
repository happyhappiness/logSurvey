		die_errno("failed to write pid file '%s'", path);
}

static int serve(struct string_list *listen_addr, int listen_port,
    struct credentials *cred)
{
	struct socketlist socklist = { NULL, 0, 0 };


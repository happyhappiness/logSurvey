	free(ctx);
}

static struct store *imap_open_store(struct imap_server_conf *srvc)
{
	struct imap_store *ctx;

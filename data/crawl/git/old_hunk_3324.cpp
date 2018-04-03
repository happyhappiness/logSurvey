	return 0;
}

static int cacheinfo_callback(struct parse_opt_ctx_t *ctx,
				const struct option *opt, int unset)
{
	unsigned char sha1[20];
	unsigned int mode;

	if (ctx->argc <= 3)
		return error("option 'cacheinfo' expects three arguments");
	if (strtoul_ui(*++ctx->argv, 8, &mode) ||
	    get_sha1_hex(*++ctx->argv, sha1) ||
	    add_cacheinfo(mode, sha1, *++ctx->argv, 0))

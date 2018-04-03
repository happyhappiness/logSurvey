		return error("cannot find the current offset");

	header_len = xsnprintf((char *)obuf, sizeof(obuf), "%s %" PRIuMAX,
			       typename(type), (uintmax_t)size) + 1;
	git_SHA1_Init(&ctx);
	git_SHA1_Update(&ctx, obuf, header_len);


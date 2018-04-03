	index_base = p->index_data;

	/* Verify SHA1 sum of the index file */
	git_SHA1_Init(&ctx);
	git_SHA1_Update(&ctx, index_base, (unsigned int)(index_size - 20));
	git_SHA1_Final(sha1, &ctx);
	if (hashcmp(sha1, index_base + index_size - 20))
		err = error("Packfile index for %s SHA1 mismatch",
			    p->pack_name);
	return err;
}
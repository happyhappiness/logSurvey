	unpack_all();
	SHA1_Update(&ctx, buffer, offset);
	SHA1_Final(sha1, &ctx);
	if (strict)
		write_rest();
	if (hashcmp(fill(20), sha1))
		die("final sha1 did not match");
	use(20);
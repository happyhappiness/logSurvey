
	/* Check pack integrity */
	flush();
	the_hash_algo->final_fn(hash, &input_ctx);
	if (hashcmp(fill(the_hash_algo->rawsz), hash))
		die(_("pack is corrupted (SHA1 mismatch)"));
	use(the_hash_algo->rawsz);

	/* If input_fd is a file, we should have reached its end now. */
	if (fstat(input_fd, &st))

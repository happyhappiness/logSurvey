	index_base = p->index_data;

	/* Verify SHA1 sum of the index file */
	the_hash_algo->init_fn(&ctx);
	the_hash_algo->update_fn(&ctx, index_base, (unsigned int)(index_size - the_hash_algo->rawsz));
	the_hash_algo->final_fn(hash, &ctx);
	if (hashcmp(hash, index_base + index_size - the_hash_algo->rawsz))
		err = error("Packfile index for %s hash mismatch",
			    p->pack_name);
	return err;
}
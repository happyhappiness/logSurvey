						 &delta_chain_length,
						 base_sha1);
		printf("%s ", sha1_to_hex(sha1));
		if (!delta_chain_length) {
			printf("%-6s %lu %lu %"PRIuMAX"\n",
			       type, size, store_size, (uintmax_t)offset);
			baseobjects++;
		}
		else {
			printf("%-6s %lu %lu %"PRIuMAX" %u %s\n",
			       type, size, store_size, (uintmax_t)offset,

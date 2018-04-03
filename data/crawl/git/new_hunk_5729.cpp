		type = packed_object_info_detail(p, offset, &size, &store_size,
						 &delta_chain_length,
						 base_sha1);
		if (!stat_only)
			printf("%s ", sha1_to_hex(sha1));
		if (!delta_chain_length) {
			if (!stat_only)
				printf("%-6s %lu %lu %"PRIuMAX"\n",
				       type, size, store_size, (uintmax_t)offset);
			baseobjects++;
		}
		else {
			if (!stat_only)
				printf("%-6s %lu %lu %"PRIuMAX" %u %s\n",
				       type, size, store_size, (uintmax_t)offset,
				       delta_chain_length, sha1_to_hex(base_sha1));
			if (delta_chain_length <= MAX_CHAIN)
				chain_histogram[delta_chain_length]++;
			else

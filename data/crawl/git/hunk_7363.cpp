 						 base_sha1);
 		printf("%s ", sha1_to_hex(sha1));
 		if (!delta_chain_length)
-			printf("%-6s %lu %"PRIuMAX"\n",
-			       type, size, (uintmax_t)offset);
+			printf("%-6s %lu %lu %"PRIuMAX"\n",
+			       type, size, store_size, (uintmax_t)offset);
 		else {
-			printf("%-6s %lu %"PRIuMAX" %u %s\n",
-			       type, size, (uintmax_t)offset,
+			printf("%-6s %lu %lu %"PRIuMAX" %u %s\n",
+			       type, size, store_size, (uintmax_t)offset,
 			       delta_chain_length, sha1_to_hex(base_sha1));
 			if (delta_chain_length <= MAX_CHAIN)
 				chain_histogram[delta_chain_length]++;
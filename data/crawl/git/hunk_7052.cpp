 	return err;
 }
 
-
-#define MAX_CHAIN 50
-
-static void show_pack_info(struct packed_git *p)
-{
-	uint32_t nr_objects, i, chain_histogram[MAX_CHAIN+1];
-
-	nr_objects = p->num_objects;
-	memset(chain_histogram, 0, sizeof(chain_histogram));
-
-	for (i = 0; i < nr_objects; i++) {
-		const unsigned char *sha1;
-		unsigned char base_sha1[20];
-		const char *type;
-		unsigned long size;
-		unsigned long store_size;
-		off_t offset;
-		unsigned int delta_chain_length;
-
-		sha1 = nth_packed_object_sha1(p, i);
-		if (!sha1)
-			die("internal error pack-check nth-packed-object");
-		offset = find_pack_entry_one(sha1, p);
-		if (!offset)
-			die("internal error pack-check find-pack-entry-one");
-
-		type = packed_object_info_detail(p, offset, &size, &store_size,
-						 &delta_chain_length,
-						 base_sha1);
-		printf("%s ", sha1_to_hex(sha1));
-		if (!delta_chain_length)
-			printf("%-6s %lu %lu %"PRIuMAX"\n",
-			       type, size, store_size, (uintmax_t)offset);
-		else {
-			printf("%-6s %lu %lu %"PRIuMAX" %u %s\n",
-			       type, size, store_size, (uintmax_t)offset,
-			       delta_chain_length, sha1_to_hex(base_sha1));
-			if (delta_chain_length <= MAX_CHAIN)
-				chain_histogram[delta_chain_length]++;
-			else
-				chain_histogram[0]++;
-		}
-	}
-
-	for (i = 0; i <= MAX_CHAIN; i++) {
-		if (!chain_histogram[i])
-			continue;
-		printf("chain length = %d: %d object%s\n", i,
-		       chain_histogram[i], chain_histogram[i] > 1 ? "s" : "");
-	}
-	if (chain_histogram[0])
-		printf("chain length > %d: %d object%s\n", MAX_CHAIN,
-		       chain_histogram[0], chain_histogram[0] > 1 ? "s" : "");
-}
-
-int verify_pack(struct packed_git *p, int verbose)
+int verify_pack(struct packed_git *p)
 {
 	off_t index_size;
 	const unsigned char *index_base;

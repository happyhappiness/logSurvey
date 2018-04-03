 	 */
 	for (j = 0; i < nr_objects; i++) {
 		struct object_entry *e = objects + i;
-		j += !e->offset && !e->preferred_base;
+		j += !e->idx.offset && !e->preferred_base;
 	}
 	if (j)
 		die("wrote %u objects as expected but %u unwritten", written, j);
 }
 
-static int sha1_sort(const void *_a, const void *_b)
-{
-	const struct object_entry *a = *(struct object_entry **)_a;
-	const struct object_entry *b = *(struct object_entry **)_b;
-	return hashcmp(a->sha1, b->sha1);
-}
-
-static uint32_t index_default_version = 1;
-static uint32_t index_off32_limit = 0x7fffffff;
-
-static void write_index_file(off_t last_obj_offset, unsigned char *sha1)
-{
-	struct sha1file *f;
-	struct object_entry **sorted_by_sha, **list, **last;
-	uint32_t array[256];
-	uint32_t i, index_version;
-	SHA_CTX ctx;
-
-	int fd = open_object_dir_tmp("tmp_idx_XXXXXX");
-	if (fd < 0)
-		die("unable to create %s: %s\n", tmpname, strerror(errno));
-	idx_tmp_name = xstrdup(tmpname);
-	f = sha1fd(fd, idx_tmp_name);
-
-	if (nr_written) {
-		sorted_by_sha = written_list;
-		qsort(sorted_by_sha, nr_written, sizeof(*sorted_by_sha), sha1_sort);
-		list = sorted_by_sha;
-		last = sorted_by_sha + nr_written;
-	} else
-		sorted_by_sha = list = last = NULL;
-
-	/* if last object's offset is >= 2^31 we should use index V2 */
-	index_version = (last_obj_offset >> 31) ? 2 : index_default_version;
-
-	/* index versions 2 and above need a header */
-	if (index_version >= 2) {
-		struct pack_idx_header hdr;
-		hdr.idx_signature = htonl(PACK_IDX_SIGNATURE);
-		hdr.idx_version = htonl(index_version);
-		sha1write(f, &hdr, sizeof(hdr));
-	}
-
-	/*
-	 * Write the first-level table (the list is sorted,
-	 * but we use a 256-entry lookup to be able to avoid
-	 * having to do eight extra binary search iterations).
-	 */
-	for (i = 0; i < 256; i++) {
-		struct object_entry **next = list;
-		while (next < last) {
-			struct object_entry *entry = *next;
-			if (entry->sha1[0] != i)
-				break;
-			next++;
-		}
-		array[i] = htonl(next - sorted_by_sha);
-		list = next;
-	}
-	sha1write(f, array, 256 * 4);
-
-	/* Compute the SHA1 hash of sorted object names. */
-	SHA1_Init(&ctx);
-
-	/* Write the actual SHA1 entries. */
-	list = sorted_by_sha;
-	for (i = 0; i < nr_written; i++) {
-		struct object_entry *entry = *list++;
-		if (index_version < 2) {
-			uint32_t offset = htonl(entry->offset);
-			sha1write(f, &offset, 4);
-		}
-		sha1write(f, entry->sha1, 20);
-		SHA1_Update(&ctx, entry->sha1, 20);
-	}
-
-	if (index_version >= 2) {
-		unsigned int nr_large_offset = 0;
-
-		/* write the crc32 table */
-		list = sorted_by_sha;
-		for (i = 0; i < nr_written; i++) {
-			struct object_entry *entry = *list++;
-			uint32_t crc32_val = htonl(entry->crc32);
-			sha1write(f, &crc32_val, 4);
-		}
-
-		/* write the 32-bit offset table */
-		list = sorted_by_sha;
-		for (i = 0; i < nr_written; i++) {
-			struct object_entry *entry = *list++;
-			uint32_t offset = (entry->offset <= index_off32_limit) ?
-				entry->offset : (0x80000000 | nr_large_offset++);
-			offset = htonl(offset);
-			sha1write(f, &offset, 4);
-		}
-
-		/* write the large offset table */
-		list = sorted_by_sha;
-		while (nr_large_offset) {
-			struct object_entry *entry = *list++;
-			uint64_t offset = entry->offset;
-			if (offset > index_off32_limit) {
-				uint32_t split[2];
-				split[0]        = htonl(offset >> 32);
-				split[1] = htonl(offset & 0xffffffff);
-				sha1write(f, split, 8);
-				nr_large_offset--;
-			}
-		}
-	}
-
-	sha1write(f, pack_file_sha1, 20);
-	sha1close(f, NULL, 1);
-	SHA1_Final(sha1, &ctx);
-}
-
 static int locate_object_entry_hash(const unsigned char *sha1)
 {
 	int i;
 	unsigned int ui;
 	memcpy(&ui, sha1, sizeof(unsigned int));
 	i = ui % object_ix_hashsz;
 	while (0 < object_ix[i]) {
-		if (!hashcmp(sha1, objects[object_ix[i] - 1].sha1))
+		if (!hashcmp(sha1, objects[object_ix[i] - 1].idx.sha1))
 			return i;
 		if (++i == object_ix_hashsz)
 			i = 0;

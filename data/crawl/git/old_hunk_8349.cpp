	free(sorted_by_pos);
}

static uint32_t index_default_version = 1;
static uint32_t index_off32_limit = 0x7fffffff;

static int sha1_compare(const void *_a, const void *_b)
{
	struct object_entry *a = *(struct object_entry **)_a;
	struct object_entry *b = *(struct object_entry **)_b;
	return hashcmp(a->sha1, b->sha1);
}

/*
 * On entry *sha1 contains the pack content SHA1 hash, on exit it is
 * the SHA1 hash of sorted object names.
 */
static const char *write_index_file(const char *index_name, unsigned char *sha1)
{
	struct sha1file *f;
	struct object_entry **sorted_by_sha, **list, **last;
	uint32_t array[256];
	int i, fd;
	SHA_CTX ctx;
	uint32_t index_version;

	if (nr_objects) {
		sorted_by_sha =
			xcalloc(nr_objects, sizeof(struct object_entry *));
		list = sorted_by_sha;
		last = sorted_by_sha + nr_objects;
		for (i = 0; i < nr_objects; ++i)
			sorted_by_sha[i] = &objects[i];
		qsort(sorted_by_sha, nr_objects, sizeof(sorted_by_sha[0]),
		      sha1_compare);
	}
	else
		sorted_by_sha = list = last = NULL;

	if (!index_name) {
		static char tmpfile[PATH_MAX];
		snprintf(tmpfile, sizeof(tmpfile),
			 "%s/tmp_idx_XXXXXX", get_object_directory());
		fd = mkstemp(tmpfile);
		index_name = xstrdup(tmpfile);
	} else {
		unlink(index_name);
		fd = open(index_name, O_CREAT|O_EXCL|O_WRONLY, 0600);
	}
	if (fd < 0)
		die("unable to create %s: %s", index_name, strerror(errno));
	f = sha1fd(fd, index_name);

	/* if last object's offset is >= 2^31 we should use index V2 */
	index_version = (objects[nr_objects-1].offset >> 31) ? 2 : index_default_version;

	/* index versions 2 and above need a header */
	if (index_version >= 2) {
		struct pack_idx_header hdr;
		hdr.idx_signature = htonl(PACK_IDX_SIGNATURE);
		hdr.idx_version = htonl(index_version);
		sha1write(f, &hdr, sizeof(hdr));
	}

	/*
	 * Write the first-level table (the list is sorted,
	 * but we use a 256-entry lookup to be able to avoid
	 * having to do eight extra binary search iterations).
	 */
	for (i = 0; i < 256; i++) {
		struct object_entry **next = list;
		while (next < last) {
			struct object_entry *obj = *next;
			if (obj->sha1[0] != i)
				break;
			next++;
		}
		array[i] = htonl(next - sorted_by_sha);
		list = next;
	}
	sha1write(f, array, 256 * 4);

	/* compute the SHA1 hash of sorted object names. */
	SHA1_Init(&ctx);

	/*
	 * Write the actual SHA1 entries..
	 */
	list = sorted_by_sha;
	for (i = 0; i < nr_objects; i++) {
		struct object_entry *obj = *list++;
		if (index_version < 2) {
			uint32_t offset = htonl(obj->offset);
			sha1write(f, &offset, 4);
		}
		sha1write(f, obj->sha1, 20);
		SHA1_Update(&ctx, obj->sha1, 20);
	}

	if (index_version >= 2) {
		unsigned int nr_large_offset = 0;

		/* write the crc32 table */
		list = sorted_by_sha;
		for (i = 0; i < nr_objects; i++) {
			struct object_entry *obj = *list++;
			uint32_t crc32_val = htonl(obj->crc32);
			sha1write(f, &crc32_val, 4);
		}

		/* write the 32-bit offset table */
		list = sorted_by_sha;
		for (i = 0; i < nr_objects; i++) {
			struct object_entry *obj = *list++;
			uint32_t offset = (obj->offset <= index_off32_limit) ?
				obj->offset : (0x80000000 | nr_large_offset++);
			offset = htonl(offset);
			sha1write(f, &offset, 4);
		}

		/* write the large offset table */
		list = sorted_by_sha;
		while (nr_large_offset) {
			struct object_entry *obj = *list++;
			uint64_t offset = obj->offset;
			if (offset > index_off32_limit) {
				uint32_t split[2];
				split[0]	= htonl(offset >> 32);
				split[1] = htonl(offset & 0xffffffff);
				sha1write(f, split, 8);
				nr_large_offset--;
			}
		}
	}

	sha1write(f, sha1, 20);
	sha1close(f, NULL, 1);
	free(sorted_by_sha);
	SHA1_Final(sha1, &ctx);
	return index_name;
}

static void final(const char *final_pack_name, const char *curr_pack_name,
		  const char *final_index_name, const char *curr_index_name,
		  const char *keep_name, const char *keep_msg,

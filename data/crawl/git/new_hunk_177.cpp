}

static int show_object_fast(
	const struct object_id *oid,
	enum object_type type,
	int exclude,
	uint32_t name_hash,
	struct packed_git *found_pack,
	off_t found_offset)
{
	fprintf(stdout, "%s\n", oid_to_hex(oid));
	return 1;
}


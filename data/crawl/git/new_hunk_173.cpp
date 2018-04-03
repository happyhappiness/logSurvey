"disabling bitmap writing, as some objects are not being packed"
);

static int add_object_entry(const struct object_id *oid, enum object_type type,
			    const char *name, int exclude)
{
	struct packed_git *found_pack = NULL;
	off_t found_offset = 0;
	uint32_t index_pos;

	if (have_duplicate_entry(oid, exclude, &index_pos))
		return 0;

	if (!want_object_in_pack(oid, exclude, &found_pack, &found_offset)) {
		/* The pack is missing an object, so it will not have closure */
		if (write_bitmap_index) {
			warning(_(no_closure_warning));

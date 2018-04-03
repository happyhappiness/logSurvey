	 */
	for (j = 0; i < nr_objects; i++) {
		struct object_entry *e = objects + i;
		j += !e->idx.offset && !e->preferred_base;
	}
	if (j)
		die("wrote %u objects as expected but %u unwritten", written, j);
}

static int locate_object_entry_hash(const unsigned char *sha1)
{
	int i;
	unsigned int ui;
	memcpy(&ui, sha1, sizeof(unsigned int));
	i = ui % object_ix_hashsz;
	while (0 < object_ix[i]) {
		if (!hashcmp(sha1, objects[object_ix[i] - 1].idx.sha1))
			return i;
		if (++i == object_ix_hashsz)
			i = 0;

	return result;
}

int do_check_packed_object_crc;

void *unpack_entry(struct packed_git *p, off_t obj_offset,
		   enum object_type *type, unsigned long *sizep)
{
	struct pack_window *w_curs = NULL;
	off_t curpos = obj_offset;
	void *data;

	if (do_check_packed_object_crc && p->index_version > 1) {
		struct revindex_entry *revidx = find_pack_revindex(p, obj_offset);
		unsigned long len = revidx[1].offset - obj_offset;
		if (check_pack_crc(p, &w_curs, obj_offset, len, revidx->nr)) {
			const unsigned char *sha1 =
				nth_packed_object_sha1(p, revidx->nr);
			error("bad packed object CRC for %s",
			      sha1_to_hex(sha1));
			mark_bad_packed_object(p, sha1);
			return NULL;
		}
	}

	*type = unpack_object_header(p, &w_curs, &curpos, sizep);
	switch (*type) {
	case OBJ_OFS_DELTA:
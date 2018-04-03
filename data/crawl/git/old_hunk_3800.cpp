
int do_check_packed_object_crc;

void *unpack_entry(struct packed_git *p, off_t obj_offset,
		   enum object_type *type, unsigned long *sizep)
{
	struct pack_window *w_curs = NULL;
	off_t curpos = obj_offset;
	void *data;

	if (log_pack_access)
		write_pack_access_log(p, obj_offset);

	if (do_check_packed_object_crc && p->index_version > 1) {
		struct revindex_entry *revidx = find_pack_revindex(p, obj_offset);
		unsigned long len = revidx[1].offset - obj_offset;
		if (check_pack_crc(p, &w_curs, obj_offset, len, revidx->nr)) {
			const unsigned char *sha1 =
				nth_packed_object_sha1(p, revidx->nr);
			error("bad packed object CRC for %s",
			      sha1_to_hex(sha1));
			mark_bad_packed_object(p, sha1);
			unuse_pack(&w_curs);
			return NULL;
		}
	}

	*type = unpack_object_header(p, &w_curs, &curpos, sizep);
	switch (*type) {
	case OBJ_OFS_DELTA:
	case OBJ_REF_DELTA:
		data = unpack_delta_entry(p, &w_curs, curpos, *sizep,
					  obj_offset, type, sizep);
		break;
	case OBJ_COMMIT:
	case OBJ_TREE:
	case OBJ_BLOB:
	case OBJ_TAG:
		data = unpack_compressed_entry(p, &w_curs, curpos, *sizep);
		break;
	default:
		data = NULL;
		error("unknown object type %i at offset %"PRIuMAX" in %s",
		      *type, (uintmax_t)obj_offset, p->pack_name);
	}
	unuse_pack(&w_curs);
	return data;
}
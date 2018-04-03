	return result;
}

void *unpack_entry(struct packed_git *p, off_t obj_offset,
		   enum object_type *type, unsigned long *sizep)
{
	struct pack_window *w_curs = NULL;
	off_t curpos = obj_offset;
	void *data;

	*type = unpack_object_header(p, &w_curs, &curpos, sizep);
	switch (*type) {
	case OBJ_OFS_DELTA:

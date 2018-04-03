	off_t base_offset;

	base_offset = get_delta_base(p, w_curs, &curpos, *type, obj_offset);
	base = cache_or_unpack_entry(p, base_offset, &base_size, type, 0);
	if (!base)
		die("failed to read delta base object"
		    " at %"PRIuMAX" from %s",
		    (uintmax_t)base_offset, p->pack_name);

	delta_data = unpack_compressed_entry(p, w_curs, curpos, delta_size);
	if (!delta_data)
		die("failed to unpack compressed delta"
		    " at %"PRIuMAX" from %s",
		    (uintmax_t)curpos, p->pack_name);
	result = patch_delta(base, base_size,
			     delta_data, delta_size,
			     sizep);

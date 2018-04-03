		    (uintmax_t)base_offset, p->pack_name);

	delta_data = unpack_compressed_entry(p, w_curs, curpos, delta_size);
	result = patch_delta(base, base_size,
			     delta_data, delta_size,
			     sizep);
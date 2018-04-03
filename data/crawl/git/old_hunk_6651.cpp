			base_offset = (base_offset << 7) + (c & 127);
		}
		base_offset = obj_list[nr].offset - base_offset;

		delta_data = get_data(delta_size);
		if (dry_run || !delta_data) {

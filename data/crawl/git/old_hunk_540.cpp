			ofs = entry->in_pack_offset - ofs;
			if (ofs <= 0 || ofs >= entry->in_pack_offset) {
				error("delta base offset out of bound for %s",
				      sha1_to_hex(entry->idx.sha1));
				goto give_up;
			}
			if (reuse_delta && !entry->preferred_base) {

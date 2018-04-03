				die("delta base offset out of bound for %s",
				    sha1_to_hex(entry->idx.sha1));
			ofs = entry->in_pack_offset - ofs;
			if (!no_reuse_delta && !entry->preferred_base)
				base_ref = find_packed_object_name(p, ofs);
			entry->in_pack_header_size = used + used_0;
			break;
		}


		} else {
			const char *dst_side = pat->dst ? pat->dst : pat->src;
			if (!match_name_with_pattern(pat->src, src->name,
						     dst_side, &dst_name))
				die("Didn't think it matches any more");
		}
		dst_peer = find_ref_by_name(dst, dst_name);
		if (dst_peer) {

		die("internal error: dst already matched.");

	src = rename_src[src_index].one;
	src->count++;

	dst = rename_dst[dst_index].two;

	if (buffer_is_binary(orig->ptr, orig->size) ||
	    buffer_is_binary(src1->ptr, src1->size) ||
	    buffer_is_binary(src2->ptr, src2->size)) {
		warning("Cannot merge binary files: %s vs. %s\n",
			name1, name2);
		return ll_binary_merge(drv_unused, result,
				       path_unused,
				       orig, src1, name1,
				       src2, name2,
				       virtual_ancestor);

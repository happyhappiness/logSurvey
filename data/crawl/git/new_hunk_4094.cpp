	if (buffer_is_binary(orig->ptr, orig->size) ||
	    buffer_is_binary(src1->ptr, src1->size) ||
	    buffer_is_binary(src2->ptr, src2->size)) {
		return ll_binary_merge(drv_unused, result,
				       path,
				       orig, orig_name,
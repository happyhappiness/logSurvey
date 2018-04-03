	d.offset = 0;
	d.dstq = &newdest; d.srcq = &target->suspects;

	fill_origin_blob(&sb->revs->diffopt, parent, &file_p);
	fill_origin_blob(&sb->revs->diffopt, target, &file_o);
	num_get_patch++;

	if (diff_hunks(&file_p, &file_o, blame_chunk_cb, &d))
		die("unable to generate diff (%s -> %s)",

		die("wrote %u objects while expecting %u", written, nr_result);
	sha1close(f, pack_file_sha1, 1);

	return last_obj_offset;
}

static int sha1_sort(const void *_a, const void *_b)

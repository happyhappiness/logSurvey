	print_line_count(lc_b);
	printf(" @@%s\n", reset);
	if (lc_a)
		copy_file_with_prefix('-', one->data, one->size, old, reset);
	if (lc_b)
		copy_file_with_prefix('+', two->data, two->size, new, reset);
}

static int fill_mmfile(mmfile_t *mf, struct diff_filespec *one)
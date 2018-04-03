	print_line_count(o->file, lc_b);
	fprintf(o->file, " @@%s\n", reset);
	if (lc_a)
		copy_file_with_prefix(o->file, '-', one->data, one->size, old, reset);
	if (lc_b)
		copy_file_with_prefix(o->file, '+', two->data, two->size, new, reset);
}

static int fill_mmfile(mmfile_t *mf, struct diff_filespec *one)

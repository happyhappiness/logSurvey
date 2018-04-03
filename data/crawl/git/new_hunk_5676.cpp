	print_line_count(o->file, lc_b);
	fprintf(o->file, " @@%s\n", reset);
	if (lc_a)
		emit_rewrite_lines(&ecbdata, '-', one->data, one->size);
	if (lc_b)
		emit_rewrite_lines(&ecbdata, '+', two->data, two->size);
}

struct diff_words_buffer {
	mmfile_t minus, plus;
	struct diff_words_style *style = diff_words->style;

	/* special case: only removal */
	if (!diff_words->plus.text.size) {
		fn_out_diff_words_write_helper(diff_words->file,
			&style->old, style->newline,
			diff_words->minus.text.size, diff_words->minus.text.ptr);
		diff_words->minus.text.size = 0;
		return;
	}

	diff_words->current_plus = diff_words->plus.text.ptr;

	memset(&xpp, 0, sizeof(xpp));
	memset(&xecfg, 0, sizeof(xecfg));

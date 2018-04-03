	free(minus.ptr);
	free(plus.ptr);
	if (diff_words->current_plus != diff_words->plus.text.ptr +
			diff_words->plus.text.size)
		fn_out_diff_words_write_helper(diff_words->file,
			&style->ctx, style->newline,
			diff_words->plus.text.ptr + diff_words->plus.text.size
			- diff_words->current_plus, diff_words->current_plus);
	diff_words->minus.text.size = diff_words->plus.text.size = 0;
}


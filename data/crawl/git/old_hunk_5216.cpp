	} else
		plus_begin = plus_end = diff_words->plus.orig[plus_first].end;

	if (diff_words->current_plus != plus_begin)
		fn_out_diff_words_write_helper(diff_words->file,
				&style->ctx, style->newline,
				plus_begin - diff_words->current_plus,
				diff_words->current_plus);
	if (minus_begin != minus_end)
		fn_out_diff_words_write_helper(diff_words->file,
				&style->old, style->newline,
				minus_end - minus_begin, minus_begin);
	if (plus_begin != plus_end)
		fn_out_diff_words_write_helper(diff_words->file,
				&style->new, style->newline,
				plus_end - plus_begin, plus_begin);

	diff_words->current_plus = plus_end;
}

/* This function starts looking at *begin, and returns 0 iff a word was found. */

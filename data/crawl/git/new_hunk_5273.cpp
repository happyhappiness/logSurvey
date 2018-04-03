
	if (len < 1) {
		emit_line(ecbdata->file, reset, reset, line, len);
		if (ecbdata->diff_words
		    && ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN)
			fputs("~\n", ecbdata->file);
		return;
	}


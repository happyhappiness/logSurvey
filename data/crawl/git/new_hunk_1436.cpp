		return;
	}

	if (ecbdata->diff_words) {
		if (line[0] == '-') {
			diff_words_append(line, len,
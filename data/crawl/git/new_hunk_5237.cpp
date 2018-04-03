		}
		diff_words_flush(ecbdata);
		if (ecbdata->diff_words->type == DIFF_WORDS_PORCELAIN) {
			emit_line(ecbdata->opt, plain, reset, line, len);
			fputs("~\n", ecbdata->opt->file);
		} else {
			/* don't print the prefix character */
			emit_line(ecbdata->opt, plain, reset, line+1, len-1);
		}
		return;
	}

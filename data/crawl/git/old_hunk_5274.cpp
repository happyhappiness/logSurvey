			return;
		}
		diff_words_flush(ecbdata);
		line++;
		len--;
		emit_line(ecbdata->file, plain, reset, line, len);
		return;
	}


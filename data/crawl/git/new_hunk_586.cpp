
	do {
		peek = fgetc(mi->input);
		if (peek == EOF) {
			fclose(cmitmsg);
			return error("empty patch: '%s'", patch);
		}
	} while (isspace(peek));
	ungetc(peek, mi->input);

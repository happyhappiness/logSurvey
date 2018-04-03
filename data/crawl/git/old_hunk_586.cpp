
	do {
		peek = fgetc(mi->input);
	} while (isspace(peek));
	ungetc(peek, mi->input);

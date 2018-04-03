
	do {
		peek = fgetc(f);
	} while (isspace(peek));
	ungetc(peek, f);


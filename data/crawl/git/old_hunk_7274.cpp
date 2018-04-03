	char type[20];
	unsigned char sha1[20];
	const char *object, *type_line, *tag_line, *tagger_line, *lb, *rb;

	if (size < 84)
		return error("wanna fool me ? you obviously got the size wrong !");

		message_size = strlen(message);
	}
	tagger = memmem(buf, message ? message - buf : size, "\ntagger ", 8);
	if (!tagger)
		die ("No tagger for tag %s", sha1_to_hex(tag->object.sha1));
	tagger++;
	tagger_end = strchrnul(tagger, '\n');

	/* handle signed tags */
	if (message) {

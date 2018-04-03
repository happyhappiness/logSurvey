	unsigned long len = end - (const unsigned char *)buf;

	if (size < len)
		die(_("too-short tree file"));
	buf = end;
	size -= len;
	desc->buffer = buf;
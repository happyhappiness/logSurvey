	fprintf(stderr, "ntlmGetString: insane: l:%d o:%d\n", l, o);
	return (NULL);
    }
    if ((flags & NEGOTIATE_ASCII) == 0) {
	/* UNICODE string */
	s = (u_short *) ((char *) hdr + o);
	d = buf;

	for (l >>= 1; l; s++, l--) {
	    c = le16toh(*s);
	    if (c > 254 || c == '\0') {
		fprintf(stderr, "ntlmGetString: bad uni: %04x\n", c);
		return (NULL);
	    }
	    *d++ = c;
	}

	*d = 0;
    } else {
	/* ASCII/OEM string */
	sc = (char *) hdr + o;
	d = buf;

	for (; l; l--) {
	    if (*sc == '\0' || !isprint((int) (unsigned char) *sc)) {
		fprintf(stderr, "ntlmGetString: bad ascii: %04x\n", *sc);
		return (NULL);
	    }

    if ((e = strrchr(buf, '\r')))
	*e = 0;

    bindpasswd = strdup(buf);
    if (!bindpasswd) {
	fprintf(stderr, PROGRAM_NAME " ERROR: can not allocate memory\n");
    }


	exit(1);
    }
    f = fopen(passwdfile, "r");
    while (fgets(buf, 8192, f) != NULL) {
	if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
	    (buf[0] == '\n'))
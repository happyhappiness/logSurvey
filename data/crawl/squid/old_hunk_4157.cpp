    if (err) {
      if (debug)
	fprintf(stderr, "%s| %s: Oversized message\n", LogTime(), PROGRAM);
      fprintf(stdout, "NA Oversized message\n");
      err = 0;
      continue;
    }

    if (debug)
      fprintf(stderr, "%s| %s: Got '%s' from squid (length: %d).\n", LogTime(), PROGRAM, buf?buf:"NULL",length);

    if (buf[0] == '\0') {
      if (debug)
	fprintf(stderr, "%s| %s: Invalid request\n", LogTime(), PROGRAM);
      fprintf(stdout, "NA Invalid request\n");
      continue;
    }

    if (strlen(buf) < 2) {
      if (debug)
	fprintf(stderr, "%s| %s: Invalid request [%s]\n", LogTime(), PROGRAM, buf);
      fprintf(stdout, "NA Invalid request\n");
      continue;
    }

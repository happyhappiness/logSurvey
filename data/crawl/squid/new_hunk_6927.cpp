	}
    }

  found:
    if (subid > (u_long) MAX_SUBID) {
	fprintf(stderr, "sub-identifier too large: %s\n", buf);
	return (0);
    }
    if ((*out_len)-- <= 0) {
	fprintf(stderr, "object identifier too long\n");
	return (0);
    }

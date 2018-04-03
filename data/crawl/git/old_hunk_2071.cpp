	va_end(ap);

	if (str_len < 0) {
		warning("vsnprintf failed: '%s'", strerror(errno));
		return;
	}

	str = malloc(st_add(str_len, 1));
	if (!str) {
		warning("malloc failed: '%s'", strerror(errno));
		return;
	}


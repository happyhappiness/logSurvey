	va_end(ap);

	if (str_len < 0) {
		warning_errno("vsnprintf failed");
		return;
	}

	str = malloc(st_add(str_len, 1));
	if (!str) {
		warning_errno("malloc failed");
		return;
	}


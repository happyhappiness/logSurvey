	char str_error[256], *err;
	int i, j;

	if (dying) {
		fputs("fatal: recursion detected in die_errno handler\n",
			stderr);
		exit(128);
	}
	dying = 1;

	err = strerror(errno);
	for (i = j = 0; err[i] && j < sizeof(str_error) - 1; ) {
		if ((str_error[j++] = err[i++]) != '%')
{
	va_list params;

	if (dying) {
		fputs("fatal: recursion detected in die handler\n", stderr);
		exit(128);
	}
	dying = 1;

	va_start(params, err);
	die_routine(err, params);
	va_end(params);

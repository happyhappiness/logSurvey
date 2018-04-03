static NORETURN void die_nicely(const char *err, va_list params)
{
	static int zombie;
	va_list x_params;

	va_copy(x_params, params);
	fputs("fatal: ", stderr);
	vfprintf(stderr, err, params);
	fputc('\n', stderr);

	if (!zombie) {
		zombie = 1;
		write_crash_report(err, x_params);
	}
	va_end(x_params);
	exit(128);
}

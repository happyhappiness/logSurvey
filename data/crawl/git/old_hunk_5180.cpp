static NORETURN void die_nicely(const char *err, va_list params)
{
	static int zombie;

	vreportf("fatal: ", err, params);

	if (!zombie) {
		char message[2 * PATH_MAX];

		zombie = 1;
		write_crash_report(message);
		end_packfile();
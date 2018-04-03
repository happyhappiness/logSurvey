
#endif /* ifndef APCMAIN */

struct apc_detail_s
{
	float linev;
	float loadpct;
	float bcharge;
	float timeleft;
	float outputv;
	float itemp;
	float battv;
	float linefreq;
};

#define BIG_BUF 4096

/*
 * Subroutine normally called by macro error_abort() to print
 * FATAL ERROR message and supplied error message
 */
static void generic_error_out(const char *file, int line, const char *fmt, ...)
{
	char buf[256];
	va_list arg_ptr;
	int i;

	snprintf(buf, sizeof(buf), _("FATAL ERROR in %s at line %d\n"), file, line);
	i = strlen(buf);
	va_start(arg_ptr, fmt);
	vsnprintf((char *)&buf[i], sizeof(buf) - i, (char *)fmt, arg_ptr);
	va_end(arg_ptr);
	fprintf(stdout, "%s", buf);

	exit(1);
}

/*

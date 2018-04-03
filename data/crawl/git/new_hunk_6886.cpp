
static void logreport(int priority, const char *err, va_list params)
{
	if (log_syslog) {
		char buf[1024];
		vsnprintf(buf, sizeof(buf), err, params);
		syslog(priority, "%s", buf);
	}
	else {
		/* Since stderr is set to linebuffered mode, the
		 * logging of different processes will not overlap
		 */
		fprintf(stderr, "[%d] ", (int)getpid());
		vfprintf(stderr, err, params);
		fputc('\n', stderr);
	}
}

static void logerror(const char *err, ...)

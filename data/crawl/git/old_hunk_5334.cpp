
static NORETURN void die_webcgi(const char *err, va_list params)
{
	char buffer[1000];

	http_status(500, "Internal Server Error");
	hdr_nocache();
	end_headers();

	vsnprintf(buffer, sizeof(buffer), err, params);
	fprintf(stderr, "fatal: %s\n", buffer);
	exit(0);
}

static char* getdir(void)
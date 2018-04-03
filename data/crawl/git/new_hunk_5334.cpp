
static NORETURN void die_webcgi(const char *err, va_list params)
{
	static int dead;

	if (!dead) {
		char buffer[1000];
		dead = 1;

		vsnprintf(buffer, sizeof(buffer), err, params);
		fprintf(stderr, "fatal: %s\n", buffer);
		http_status(500, "Internal Server Error");
		hdr_nocache();
		end_headers();
	}
	exit(0); /* we successfully reported a failure ;-) */
}

static char* getdir(void)
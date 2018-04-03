
static unsigned char current_commit_sha1[20];

void walker_say(struct walker *walker, const char *fmt, ...)
{
	if (walker->get_verbosely) {
		va_list ap;
		va_start(ap, fmt);
		vfprintf(stderr, fmt, ap);
		va_end(ap);
	}
}

static void report_missing(const struct object *obj)

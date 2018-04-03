	write_or_die(fd, buffer, n);
}

static void http_status(unsigned code, const char *msg)
{
	format_write(1, "Status: %u %s\r\n", code, msg);
}

static void hdr_str(const char *name, const char *value)
{
	format_write(1, "%s: %s\r\n", name, value);
}

static void hdr_int(const char *name, uintmax_t value)
{
	format_write(1, "%s: %" PRIuMAX "\r\n", name, value);
}

static void hdr_date(const char *name, unsigned long when)
{
	const char *value = show_date(when, 0, DATE_MODE(RFC2822));
	hdr_str(name, value);
}

static void hdr_nocache(void)
{
	hdr_str("Expires", "Fri, 01 Jan 1980 00:00:00 GMT");
	hdr_str("Pragma", "no-cache");
	hdr_str("Cache-Control", "no-cache, max-age=0, must-revalidate");
}

static void hdr_cache_forever(void)
{
	unsigned long now = time(NULL);
	hdr_date("Date", now);
	hdr_date("Expires", now + 31536000);
	hdr_str("Cache-Control", "public, max-age=31536000");
}

static void end_headers(void)
{
	write_or_die(1, "\r\n", 2);
}

__attribute__((format (printf, 1, 2)))
static NORETURN void not_found(const char *err, ...)
{
	va_list params;

	http_status(404, "Not Found");
	hdr_nocache();
	end_headers();

	va_start(params, err);
	if (err && *err)

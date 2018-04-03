	return len;
}

void write_file(const char *path, const char *fmt, ...)
{
	va_list params;
	struct strbuf sb = STRBUF_INIT;
	int fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		die_errno(_("could not open %s for writing"), path);

	va_start(params, fmt);
	strbuf_vaddf(&sb, fmt, params);
	va_end(params);

	strbuf_complete_line(&sb);
	if (write_in_full(fd, sb.buf, sb.len) != sb.len)
		die_errno(_("could not write to %s"), path);
	strbuf_release(&sb);
	if (close(fd))
		die_errno(_("could not close %s"), path);
}

void sleep_millisec(int millisec)
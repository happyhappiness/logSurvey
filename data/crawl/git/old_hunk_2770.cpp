	return strbuf_detach(&sb, NULL);
}

static int write_file_v(const char *path, int fatal,
			const char *fmt, va_list params)
{
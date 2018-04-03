	}
}

static void output(int v, const char *fmt, ...)
{
	int len;
	va_list ap;

	if (!show(v))
		return;

	strbuf_grow(&obuf, call_depth * 2 + 2);

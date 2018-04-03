	return !strcasecmp(src, dst);
}

/*
 * Wrapper for fprintf and returns the total number of columns required
 * for the printed string, assuming that the string is utf8.
 */
int utf8_fprintf(FILE *stream, const char *format, ...)
{
	struct strbuf buf = STRBUF_INIT;
	va_list arg;
	int columns;

	va_start(arg, format);
	strbuf_vaddf(&buf, format, arg);
	va_end(arg);

	columns = fputs(buf.buf, stream);
	if (0 <= columns) /* keep the error from the I/O */
		columns = utf8_strwidth(buf.buf);
	strbuf_release(&buf);
	return columns;
}

/*
 * Given a buffer and its encoding, return it re-encoded
 * with iconv.  If the conversion fails, returns NULL.

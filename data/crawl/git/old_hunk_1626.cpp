{
	va_list params;

	flush_output(o);
	va_start(params, err);
	strbuf_vaddf(&o->obuf, err, params);
	va_end(params);
	error("%s", o->obuf.buf);
	strbuf_reset(&o->obuf);

	return -1;
}

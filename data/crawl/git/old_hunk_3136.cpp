		return fsck_tag((struct tag *) obj, (const char *) data,
			size, options);

	return options->error_func(obj, FSCK_ERROR, "unknown type '%d' (internal fsck error)",
			  obj->type);
}

int fsck_error_function(struct object *obj, int type, const char *fmt, ...)
{
	va_list ap;
	struct strbuf sb = STRBUF_INIT;

	strbuf_addf(&sb, "object %s:", sha1_to_hex(obj->sha1));

	va_start(ap, fmt);
	strbuf_vaddf(&sb, fmt, ap);
	va_end(ap);

	error("%s", sb.buf);
	strbuf_release(&sb);
	return 1;
}

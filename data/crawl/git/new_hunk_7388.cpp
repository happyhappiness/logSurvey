	return error_func(obj, FSCK_ERROR, "unknown type '%d' (internal fsck error)",
			  obj->type);
}

int fsck_error_function(struct object *obj, int type, const char *fmt, ...)
{
	va_list ap;
	int len;
	struct strbuf sb;

	strbuf_init(&sb, 0);
	strbuf_addf(&sb, "object %s:", obj->sha1?sha1_to_hex(obj->sha1):"(null)");

	va_start(ap, fmt);
	len = vsnprintf(sb.buf + sb.len, strbuf_avail(&sb), fmt, ap);
	va_end(ap);

	if (len < 0)
		len = 0;
	if (len >= strbuf_avail(&sb)) {
		strbuf_grow(&sb, len + 2);
		va_start(ap, fmt);
		len = vsnprintf(sb.buf + sb.len, strbuf_avail(&sb), fmt, ap);
		va_end(ap);
		if (len >= strbuf_avail(&sb))
			die("this should not happen, your snprintf is broken");
	}

	error(sb.buf);
	strbuf_release(&sb);
	return 1;
}

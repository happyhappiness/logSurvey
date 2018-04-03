{
	if (fwrite(sb->buf, 1, sb->len, out) == sb->len)	/* Success. */
		return 0;
	return error_errno("cannot write delta postimage");
}

static int error_short_read(struct line_buffer *input)
{
	if (buffer_ferror(input))
		return error_errno("error reading delta");
	return error("invalid delta: unexpected end of file");
}

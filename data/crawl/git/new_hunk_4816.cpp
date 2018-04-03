	return err;
}

FILE *buffer_tmpfile_rewind(struct line_buffer *buf)
{
	rewind(buf->infile);
	return buf->infile;
}

long buffer_tmpfile_prepare_to_read(struct line_buffer *buf)
{
	long pos = ftell(buf->infile);
	if (pos < 0)
		return error("ftell error: %s", strerror(errno));
	if (fseek(buf->infile, 0, SEEK_SET))
		return error("seek error: %s", strerror(errno));
	return pos;
}

int buffer_read_char(struct line_buffer *buf)
{
	return fgetc(buf->infile);

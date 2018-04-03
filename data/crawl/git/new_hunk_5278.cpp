static int write_compressed(struct sha1file *f, void *in, unsigned int size)
{
	z_stream stream;
	int status;
	unsigned char outbuf[4096];

	memset(&stream, 0, sizeof(stream));
	deflateInit(&stream, zlib_compression_level);
	stream.next_in = in;
	stream.avail_in = size;

	do {
		stream.next_out = outbuf;
		stream.avail_out = sizeof(outbuf);
		status = deflate(&stream, Z_FINISH);
		sha1write(f, outbuf, sizeof(outbuf) - stream.avail_out);
	} while (status == Z_OK);

	if (status != Z_STREAM_END)
		die("unable to deflate appended object (%d)", status);
	size = stream.total_out;
	deflateEnd(&stream);
	return size;
}

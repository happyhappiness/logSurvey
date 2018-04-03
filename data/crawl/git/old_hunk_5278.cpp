static int write_compressed(struct sha1file *f, void *in, unsigned int size)
{
	z_stream stream;
	unsigned long maxsize;
	void *out;

	memset(&stream, 0, sizeof(stream));
	deflateInit(&stream, zlib_compression_level);
	maxsize = deflateBound(&stream, size);
	out = xmalloc(maxsize);

	/* Compress it */
	stream.next_in = in;
	stream.avail_in = size;
	stream.next_out = out;
	stream.avail_out = maxsize;
	while (deflate(&stream, Z_FINISH) == Z_OK);
	deflateEnd(&stream);

	size = stream.total_out;
	sha1write(f, out, size);
	free(out);
	return size;
}

	return foreach_alt_odb(loose_from_alt_odb, &alt);
}

static int check_stream_sha1(git_zstream *stream,
			     const char *hdr,
			     unsigned long size,
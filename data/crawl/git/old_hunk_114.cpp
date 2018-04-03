	if (stream.total_out != size || status != Z_STREAM_END)
		bad_object(offset, _("inflate returned %d"), status);
	git_inflate_end(&stream);
	if (sha1)
		git_SHA1_Final(sha1, &c);
	return buf == fixed_buf ? NULL : buf;
}

static void *unpack_raw_entry(struct object_entry *obj,
			      off_t *ofs_offset,
			      unsigned char *ref_sha1,
			      unsigned char *sha1)
{
	unsigned char *p;
	unsigned long size, c;

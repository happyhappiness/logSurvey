	return 0;
}

static int show_tag_object(const unsigned char *sha1, struct rev_info *rev)
{
	unsigned long size;
	enum object_type type;
	char *buf = read_sha1_file(sha1, &type, &size);
	int offset = 0;

	if (!buf)
		return error(_("Could not read object %s"), sha1_to_hex(sha1));

	assert(type == OBJ_TAG);
	while (offset < size && buf[offset] != '\n') {

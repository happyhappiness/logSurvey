	free(buf);
}

static int build_tag_object(struct strbuf *buf, int sign, unsigned char *result)
{
	if (sign && do_sign(buf) < 0)
		return error("unable to sign the tag");
	if (write_sha1_file(buf->buf, buf->len, tag_type, result) < 0)
		return error("unable to write tag file");
	return 0;
}

static void create_tag(const unsigned char *object, const char *tag,
		       struct strbuf *buf, int message, int sign,
		       unsigned char *prev, unsigned char *result)
{
	enum object_type type;
	char header_buf[1024];
	int header_len;
	char *path = NULL;

	type = sha1_object_info(object, NULL);
	if (type <= OBJ_NONE)

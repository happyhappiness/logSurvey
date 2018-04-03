	free(buf);
}

static void create_tag(const unsigned char *object, const char *tag,
		       struct strbuf *buf, int message, int sign,
		       unsigned char *prev, unsigned char *result)
{
	enum object_type type;
	char header_buf[1024];
	int header_len;

	type = sha1_object_info(object, NULL);
	if (type <= OBJ_NONE)

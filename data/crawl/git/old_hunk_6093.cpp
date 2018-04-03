	unsigned long *p_lno;
};

static char *grab_blob(const unsigned char *sha1, unsigned long *size)
{
	char *blob;
	enum object_type type;
	if (is_null_sha1(sha1)) {
		/* deleted blob */
		*size = 0;
		return xcalloc(1, 1);
	}
	blob = read_sha1_file(sha1, &type, size);
	if (type != OBJ_BLOB)
		die("object '%s' is not a blob!", sha1_to_hex(sha1));
	return blob;
}


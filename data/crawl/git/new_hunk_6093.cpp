	unsigned long *p_lno;
};

static char *grab_blob(const unsigned char *sha1, unsigned int mode, unsigned long *size)
{
	char *blob;
	enum object_type type;

	if (S_ISGITLINK(mode)) {
		blob = xmalloc(100);
		*size = snprintf(blob, 100,
				 "Subproject commit %s\n", sha1_to_hex(sha1));
	} else if (is_null_sha1(sha1)) {
		/* deleted blob */
		*size = 0;
		return xcalloc(1, 1);
	} else {
		blob = read_sha1_file(sha1, &type, size);
		if (type != OBJ_BLOB)
			die("object '%s' is not a blob!", sha1_to_hex(sha1));
	}
	return blob;
}


	return result;
}

static void fill_sha1_path(char *pathbuf, const unsigned char *sha1)
{
	int i;
	for (i = 0; i < 20; i++) {
		static char hex[] = "0123456789abcdef";
		unsigned int val = sha1[i];
		*pathbuf++ = hex[val >> 4];
		*pathbuf++ = hex[val & 0xf];
		if (!i)
			*pathbuf++ = '/';
	}
	*pathbuf = '\0';
}

const char *sha1_file_name(const unsigned char *sha1)
{
	static char buf[PATH_MAX];
	const char *objdir;
	int len;

	objdir = get_object_directory();
	len = strlen(objdir);

	/* '/' + sha1(2) + '/' + sha1(38) + '\0' */
	if (len + 43 > PATH_MAX)
		die("insanely long object directory %s", objdir);
	memcpy(buf, objdir, len);
	buf[len] = '/';
	fill_sha1_path(buf + len + 1, sha1);
	return buf;
}

struct strbuf *alt_scratch_buf(struct alternate_object_database *alt)

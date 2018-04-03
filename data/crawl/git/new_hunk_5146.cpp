	return (is_null_sha1(sha) || mode == 0) ? NULL: (unsigned char *)sha;
}

static int read_sha1_strbuf(const unsigned char *sha1, struct strbuf *dst)
{
	void *buf;
	enum object_type type;
	unsigned long size;
	buf = read_sha1_file(sha1, &type, &size);
	if (!buf)
		return error("cannot read object %s", sha1_to_hex(sha1));
	if (type != OBJ_BLOB) {
		free(buf);
		return error("object %s is not a blob", sha1_to_hex(sha1));
	}
	strbuf_attach(dst, buf, size, size + 1);
	return 0;
}

static int blob_unchanged(const unsigned char *o_sha,
			  const unsigned char *a_sha,
			  const char *path)
{
	struct strbuf o = STRBUF_INIT;
	struct strbuf a = STRBUF_INIT;
	int ret = 0; /* assume changed for safety */

	if (sha_eq(o_sha, a_sha))
		return 1;
	if (!merge_renormalize)
		return 0;

	assert(o_sha && a_sha);
	if (read_sha1_strbuf(o_sha, &o) || read_sha1_strbuf(a_sha, &a))
		goto error_return;
	/*
	 * Note: binary | is used so that both renormalizations are
	 * performed.  Comparison can be skipped if both files are
	 * unchanged since their sha1s have already been compared.
	 */
	if (renormalize_buffer(path, o.buf, o.len, &o) |
	    renormalize_buffer(path, a.buf, o.len, &a))
		ret = (o.len == a.len && !memcmp(o.buf, a.buf, o.len));

error_return:
	strbuf_release(&o);
	strbuf_release(&a);
	return ret;
}

/* Per entry merge function */
static int process_entry(struct merge_options *o,
			 const char *path, struct stage_data *entry)

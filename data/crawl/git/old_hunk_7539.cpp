	}
	else {
		/* Otherwise, the old one must be empty. */
		if (buf->len)
			return error("the patch applies to an empty "
				     "'%s' but it is not empty", name);
	}

	get_sha1_hex(patch->new_sha1_prefix, sha1);
	if (is_null_sha1(sha1)) {
		strbuf_release(buf);
		return 0; /* deletion patch */
	}

